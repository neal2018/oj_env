#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<array<int, 2>>> g(n);
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w, u--, v--;
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    vector<int> seen(n);
    int cur = 0;
    function<void(int)> dfs = [&](int node) {
      seen[node] = 1;
      res = max(res, cur);
      for (auto& [ne, w] : g[node]) {
        if (seen[ne]) continue;
        cur += w;
        dfs(ne);
        cur -= w;
      }
      seen[node] = 0;
    };
    dfs(i);
  }
  cout << res << "\n";
}
