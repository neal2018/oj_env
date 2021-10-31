#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, q, u, v;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  cin >> q;
  vector<int> deg(n);
  vector<pair<int, int>> qs(q);
  for (int i = 0; i < q; i++) {
    cin >> u >> v;
    u--, v--;
    qs[i] = {u, v};
    deg[u] = 1 - deg[u], deg[v] = 1 - deg[v];
  }
  int cnt = accumulate(deg.begin(), deg.end(), 0);
  vector<int> seen(n), dep(n), fa(n);
  function<void(int)> dfs = [&](int node) {
    seen[node] = 1;
    for (auto& ne : g[node]) {
      if (seen[ne] == 0) {
        seen[ne] = 1, fa[ne] = node;
        dep[ne] = dep[node] + 1;
        dfs(ne);
      }
    }
  };
  dfs(0);
  cin >> q;
  vector<int> need(n, -1);  // if start from i, need to go to need[i]
  if (cnt == 0) {
    cout << "YES\n";
    for (int i = 0; i < q; i++) {
      auto [x, y] = qs[i];
      vector<int> l, r;
      while (x != y) {
        if (dep[x] > dep[y]) {
          l.push_back(x);
          x = fa[x];
        } else {
          r.push_back(y);
          y = fa[y];
        }
      }
      l.push_back(x);
      l.insert(l.end(), r.rbegin(), r.rend());
      cout << l.size() << '\n';
      for (auto& t : l) cout << t + 1 << ' ';
      cout << '\n';
    }
  } else {
    cout << "NO\n";
    cout << (cnt / 2) << '\n';
  }
}