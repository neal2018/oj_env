#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back({v, i}), g[v].push_back({u, i});
  }
  if (m != n) {
    cout << 0 << '\n';
    return 0;
  }
  ll cnt = 1, node_cnt, edge_cnt;
  vector<int> seen(n), seen_edge(m);
  function<void(int, int)> dfs = [&](int node, int fa) {
    if (seen[node]) return 0;
    node_cnt++;
    seen[node] = 1;
    for (auto& [ne, e] : g[node]) {
      if (seen_edge[e] == 0) edge_cnt++, seen_edge[e] = 1;
      if (ne != fa) dfs(ne, node);
    }
    return 0;
  };
  for (int i = 0; i < n; i++)
    if (seen[i] == 0) {
      cnt = (cnt * 2) % MOD;
      node_cnt = 0, edge_cnt = 0;
      dfs(i, -1);
      if (node_cnt != edge_cnt) {
        cout << 0 << '\n';
        return 0;
      }
    }
  cout << cnt << '\n';
}