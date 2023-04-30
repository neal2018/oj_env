#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }

  vector<ll> dp(n), sz(n);
  vector<int> parent(n);
  vector<set<array<ll, 2>>> sons(n);
  function<void(int, int)> dfs = [&](int node, int fa) {
    parent[node] = fa;
    sz[node] = 1;
    dp[node] = a[node];
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
      sons[node].insert({-sz[ne], ne});
      sz[node] += sz[ne];
      dp[node] += dp[ne];
    }
  };
  dfs(0, -1);
  while (q--) {
    int t, x;
    cin >> t >> x, x--;
    if (t == 1) {
      cout << dp[x] << "\n";
    } else {
      if (sz[x] == 1) continue;
      auto h_son = (*sons[x].begin())[1];
      auto fa = parent[x];
      // cut x and x_fa
      {
        dp[fa] -= dp[x];
        sons[fa].erase({-sz[x], x});
      }
      // cut h_son and x
      {
        sz[x] -= sz[h_son];
        dp[x] -= dp[h_son];
        sons[x].erase(sons[x].begin());
      }
      // link h_son and x
      {
        parent[x] = h_son;
        sz[h_son] += sz[x];
        dp[h_son] += dp[x];
        sons[h_son].insert({-sz[x], x});
      }
      // link fa and h_son
      {
        parent[h_son] = fa;
        dp[fa] += dp[h_son];
        sons[fa].insert({-sz[h_son], h_son});
      }
    }
  }
}
