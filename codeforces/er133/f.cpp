#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto scc(vector<vector<int>>& g) {
  int n = int(g.size()), cnt = 0;
  vector<int> out(n, -1), idx(n, -1), order(n);
  vector<vector<int>> g_inv(n);
  function<void(int)> dfs = [&](int node) {
    out[node] = -2;
    for (auto& ne : g[node]) {
      g_inv[ne].push_back(node);
      if (out[ne] == -1) dfs(ne);
    }
    out[node] = cnt++;
  };
  for (int i = 0; i < n; i++) {
    if (out[i] == -1) dfs(i);
  }
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int u, int v) { return out[u] > out[v]; });
  cnt = 0;
  for (auto i : order) {
    if (idx[i] != -1) continue;
    vector<int> s{i};
    while (!s.empty()) {
      int cur = s.back();
      s.pop_back(), idx[cur] = cnt;
      for (auto& ne : g_inv[cur]) {
        if (idx[ne] == -1) s.push_back(ne);
      }
    }
    cnt++;
  }
  return idx;
}

// 0 => impossible, 1 => possible, 0-based
auto two_sat(int n, vector<array<int, 4>>& clauses) {
  vector<int> res(n);
  vector<vector<int>> g(2 * n);
  for (auto& [x, is_x, y, is_y] : clauses) {
    g[x + is_x * n].push_back(y + (!is_y) * n);
    g[y + is_y * n].push_back(x + (!is_x) * n);
  }
  auto idx = scc(g);
  for (int i = 0; i < n; i++) {
    if (idx[i] == idx[i + n]) return pair{0, res};
    res[i] = idx[i + n] < idx[i];
  }
  return pair{1, res};
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 4>> clauses;
    clauses.reserve(8 * (n + m) * k);
    // n*k, <=t => 2*i*k + t, >= t => 2*i*k + k + t
    for (auto i : views::iota(0, n)) {
      int offset = 2 * i * k;
      // <= t + 1 => <= t
      for (int t = 0; t < k - 1; t++) clauses.push_back({offset + t, 0, offset + t + 1, 1});
      // >= t => >= t - 1
      for (int t = 1; t < k; t++) clauses.push_back({offset + k + t, 0, offset + k + t - 1, 1});
      // <= t <=> !(>= t + 1)
      for (int t = 0; t < k - 1; t++) clauses.push_back({offset + t, 1, offset + k + t + 1, 1});
      for (int t = 0; t < k - 1; t++) clauses.push_back({offset + t, 0, offset + k + t + 1, 0});
      // x >= 0
      clauses.push_back({offset + k, 1, offset + k, 1});
      // x <= k-1
      clauses.push_back({offset + k - 1, 1, offset + k - 1, 1});
    }
    // non-decreasing
    for (auto i : views::iota(0, n - 1)) {
      int offset = 2 * i * k;
      int offset_nex = 2 * (i + 1) * k;
      // a[i] >= t => a[i+1] >=t
      for (auto t : views::iota(0, k)) {
        clauses.push_back({offset + k + t, 0, offset_nex + k + t, 1});
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
        clauses.push_back({offset + k + t, 0, offset + t, 0});
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
            clauses.push_back({offset_j + k + t + 1 - ii, 0, offset_j + k + t + 1 - ii, 0});
          } else if (t + 1 - ii < 0) {
            // ban x
            clauses.push_back({offset_i + k + ii, 0, offset_i + k + ii, 0});
          } else if (0 <= ii && ii < k && 0 <= t + 1 - ii && t + 1 - ii < k) {
            clauses.push_back({offset_i + k + ii, 0, offset_j + k + t + 1 - ii, 0});
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
            clauses.push_back({offset_j + t - 1 - ii, 0, offset_j + t - 1 - ii, 0});
          } else if (t - 1 - ii >= k) {
            // ban x
            clauses.push_back({offset_i + ii, 0, offset_i + ii, 0});
          } else if (0 <= ii && ii < k && 0 <= t - 1 - ii && t - 1 - ii < k) {
            clauses.push_back({offset_i + ii, 0, offset_j + t - 1 - ii, 0});
          }
        }
      }
    }
    auto&& [nice, sol] = two_sat(2 * n * k, clauses);
    if (!nice) {
      cout << "-1\n";
    } else {
      for (auto i : views::iota(0, n)) {
        int offset = 2 * i * k;
        for (int t = 0; t < k; t++) {
          if (sol[offset + t] == 1 && sol[offset + k + t] == 1) {
            cout << t + 1 << " ";
            break;
          }
        }
      }
      cout << "\n";
    }
  }
}
