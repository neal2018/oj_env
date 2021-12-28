#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, m;
  cin >> T;
  for (; T--;) {
    cin >> n >> m;
    vector g(n, vector<pair<int, int>>());
    vector<int> p(2 * n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
    auto merge = [&](int x, int y) { p[find(x)] = find(y); };
    int f = 1;
    auto add = [&](int u, int v, int t) {
      if (__builtin_popcount(t) % 2 == 0) {
        if (find(u) == find(v + n)) {
          f = 0;
        } else {
          merge(u, v), merge(u + n, v + n);
        }
      } else {
        if (find(u) == find(v)) {
          f = 0;
        } else {
          merge(u + n, v), merge(u, v + n);
        }
      }
    };
    for (int i = 0, u, v, t; i < n - 1; i++) {
      cin >> u >> v >> t;
      u--, v--;
      g[u].push_back({v, t}), g[v].push_back({u, t});
      if (t != -1) add(u, v, t);
    }
    for (int i = 0, u, v, t; i < m; i++) {
      cin >> u >> v >> t;
      u--, v--;
      add(u, v, t);
    }
    if (!f) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<int> w(2 * n), seen(2 * n);
    for (int i = 0; i < n; i++) {
      int r = find(i), op = find(i + n);
      if (!seen[r] && !seen[op]) {
        w[r] = 0, w[op] = 1;
        seen[r] = 1, seen[op] = 1;
      }
    }
    function<void(int, int)> dfs = [&](int node, int fa) {
      for (auto& [ne, t] : g[node]) {
        if (ne == fa) continue;
        if (t != -1) {
          cout << ne + 1 << " " << node + 1 << " " << t << "\n";
        } else if (w[find(node)] != w[find(ne)]) {
          cout << ne + 1 << " " << node + 1 << " 1\n";
        } else {
          cout << ne + 1 << " " << node + 1 << " 0\n";
        }
        dfs(ne, node);
      }
    };
    dfs(0, -1);
  }
}