#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0, u, v, c; i < n - 1; i++) {
    cin >> u >> v >> c, u--, v--, c--;
    g[u].push_back({v, c}), g[v].push_back({u, c});
  }
  vector<int> sz(n, 1), cnt(2 * n);  // sub tree, connected components
  vector<int> parent(n);
  vector<vector<int>> stk(n);
  // root of the virtual tree
  for (int i = 0; i < n; i++) stk[i].push_back(i + n), cnt[i + n] = n;
  function<void(int, int)> dfs = [&](int node, int fa) {
    for (auto& [ne, c] : g[node]) {
      if (ne == fa) continue;
      stk[c].push_back(ne);
      dfs(ne, node);
      stk[c].pop_back();
      sz[node] += sz[ne];
      parent[ne] = stk[c].back();
      cnt[stk[c].back()] -= sz[ne];
    }
    cnt[node] += sz[node];
  };
  dfs(0, -1);
  ll res = 0;
  for (int i = 1; i < n; i++) res +=(ll)cnt[i] * cnt[parent[i]];
  cout << res << "\n";
}
