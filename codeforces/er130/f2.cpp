#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct TwoSat {
  int n;
  vector<vector<int>> g;
  vector<bool> res;
  TwoSat(int _n) : n(_n), g(2 * n), res(n) {}
  void add_clause(int u, bool is_u, int v, bool is_v) {
    g[2 * u + !is_u].push_back(2 * v + is_v);
    g[2 * v + !is_v].push_back(2 * u + is_u);
  }
  bool solve() {
    int cnt = 0, now = 0;
    vector<int> dfn(2 * n, -1), low(2 * n), id(2 * n, -1), stk;
    function<void(int)> tarjan = [&](int node) {
      dfn[node] = low[node] = now++, stk.push_back(node);
      for (auto& ne : g[node]) {
        if (dfn[ne] == -1) {
          tarjan(ne);
          low[node] = min(low[node], low[ne]);
        } else if (id[ne] == -1) {
          low[node] = min(low[node], dfn[ne]);
        }
      }
      if (dfn[node] == low[node]) {
        while (true) {
          auto v = stk.back();
          id[v] = cnt;
          stk.pop_back();
          if (v == node) break;
        }
        ++cnt;
      }
    };
    for (int i = 0; i < 2 * n; ++i) {
      if (dfn[i] == -1) tarjan(i);
    }
    for (int i = 0; i < n; ++i) {
      if (id[2 * i] == id[2 * i + 1]) return false;
      res[i] = id[2 * i] > id[2 * i + 1];
    }
    return true;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    TwoSat ts(2 * n * k);
    // n*k, <=t => 2*i*k + t, >= t => 2*i*k + k + t
    for (auto i : views::iota(0, n)) {
      int offset = 2 * i * k;
      // <= t + 1 => <= t
      for (int t = 0; t < k - 1; t++) ts.add_clause(offset + t, 0, offset + t + 1, 1);
      // >= t => >= t - 1
      for (int t = 1; t < k; t++) ts.add_clause(offset + k + t, 0, offset + k + t - 1, 1);
      // <= t <=> !(>= t + 1)
      for (int t = 0; t < k - 1; t++) ts.add_clause(offset + t, 1, offset + k + t + 1, 1);
      for (int t = 0; t < k - 1; t++) ts.add_clause(offset + t, 0, offset + k + t + 1, 0);
      // x >= 0
      ts.add_clause(offset + k, 1, offset + k, 1);
      // x <= k-1
      ts.add_clause(offset + k - 1, 1, offset + k - 1, 1);
    }
    // non-decreasing
    for (auto i : views::iota(0, n - 1)) {
      int offset = 2 * i * k;
      int offset_nex = 2 * (i + 1) * k;
      // a[i] >= t => a[i+1] >=t
      for (auto t : views::iota(0, k)) {
        ts.add_clause(offset + k + t, 0, offset_nex + k + t, 1);
      }
    }
    while (m--) {
      int op;
      cin >> op;
      if (op == 1) {
        int i, t;
        cin >> i >> t, i--, t--;
        // !(x >= t && x <= t)
        int offset = 2 * i * k;
        ts.add_clause(offset + k + t, 0, offset + t, 0);
      } else if (op == 2) {
        int i, j, t;
        cin >> i >> j >> t, i--, j--, t -= 2;
        int offset_i = 2 * i * k, offset_j = 2 * j * k;
        // !(x >= ii && y >= t + 1 - ii)
        //  0 <= t + 1 - ii < k
        //  t + 1 - k < ii <= t + 1
        for (auto ii : views::iota(min(0, t + 2 - k), max(k, t + 2))) {
          if (ii < 0) {
            // ban y
            ts.add_clause(offset_j + k + t + 1 - ii, 0, offset_j + k + t + 1 - ii, 0);
          } else if (t + 1 - ii < 0) {
            // ban x
            ts.add_clause(offset_i + k + ii, 0, offset_i + k + ii, 0);
          } else if (0 <= ii && ii < k && 0 <= t + 1 - ii && t + 1 - ii < k) {
            ts.add_clause(offset_i + k + ii, 0, offset_j + k + t + 1 - ii, 0);
          }
        }
      } else {
        int i, j, t;
        cin >> i >> j >> t, i--, j--, t -= 2;
        int offset_i = 2 * i * k, offset_j = 2 * j * k;
        // !(x <= ii && y <= t - 1 - ii)
        //  0 <= t - 1 - ii < k
        //  t - 1 - k < ii <= t - 1
        for (auto ii : views::iota(min(0, t - k), max(k, t))) {
          if (ii >= k) {
            // ban y
            ts.add_clause(offset_j + t - 1 - ii, 0, offset_j + t - 1 - ii, 0);
          } else if (t - 1 - ii >= k) {
            // ban x
           ts.add_clause(offset_i + ii, 0, offset_i + ii, 0);
          } else if (0 <= ii && ii < k && 0 <= t - 1 - ii && t - 1 - ii < k) {
            ts.add_clause(offset_i + ii, 0, offset_j + t - 1 - ii, 0);
          }
        }
      }
    }
    auto nice = ts.solve();
    if (!nice) {
      cout << "-1\n";
    } else {
      for (auto i : views::iota(0, n)) {
        int offset = 2 * i * k;
        for (int t = 0; t < k; t++) {
          if (ts.res[offset + t] == 1 && ts.res[offset + k + t] == 1) {
            cout << t + 1 << " ";
            break;
          }
        }
      }
      cout << "\n";
    }
  }
}
