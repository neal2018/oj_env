#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

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

constexpr int SZ = 26;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> depth(n), parent(n, -1);
  function<void(int, int)> get_dep = [&](int node, int fa) {
    if (fa != -1) depth[node] = depth[fa] + 1, parent[node] = fa;
    for (auto& ne : g[node]) {
      if (ne != fa) get_dep(ne, node);
    }
  };
  get_dep(0, -1);
  auto get_path = [&](int x, int y) {
    vector<int> left, right;
    while (x != y) {
      if (depth[x] > depth[y]) {
        left.push_back(x);
        x = parent[x];
      } else {
        right.push_back(y);
        y = parent[y];
      }
    }
    left.push_back(x);
    reverse(right.begin(), right.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
  };
  TwoSat ts(n * SZ);
  while (q--) {
    int x, y;
    string s;
    cin >> x >> y >> s, x--, y--;
    auto path = get_path(x, y);
    int sz = int(s.size());
    for (int i = 0; i < sz; i++) {
      int a = s[i] - 'a', b = s[sz - 1 - i] - 'a', node = path[i];
      for (auto j : views::iota(0, SZ)) {
        if (j != a && j != b) {
          ts.add_clause(SZ * node + j, 0, SZ * node + j, 0);
        }
      }
      ts.add_clause(SZ * node + a, 1, SZ * node + b, 1);
      if (a != b) ts.add_clause(SZ * node + a, 0, SZ * node + b, 0);
    }
    auto t = string(s.rbegin(), s.rend());
    if (t != s) {
      int id = 0;
      while (t[id] == s[id]) id++;
      for (int i = 0; i < sz; i++) {
        if (i == id || s[sz - 1 - i] == s[i]) continue;
        ts.add_clause(SZ * path[i] + s[i] - 'a', 1, SZ * path[id] + s[id] - 'a', 0);
        ts.add_clause(SZ * path[i] + s[i] - 'a', 0, SZ * path[id] + s[id] - 'a', 1);
        ts.add_clause(SZ * path[i] + s[sz - 1 - i] - 'a', 1, SZ * path[id] + s[sz - 1 - id] - 'a',
                      0);
        ts.add_clause(SZ * path[i] + s[sz - 1 - i] - 'a', 0, SZ * path[id] + s[sz - 1 - id] - 'a',
                      1);
      }
    }
  }

  auto nice = ts.solve();
  if (!nice) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      int f = 0;
      for (int j = 0; j < SZ; j++) {
        if (ts.res[SZ * i + j]) {
          cout << char('a' + j);
          f = 1;
          break;
        }
      }
      if (!f) cout << 'a';
    }
    cout << "\n";
  }
}
