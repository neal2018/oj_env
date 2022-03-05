#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, inf = 1e9;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  int cur = 0;
  vector<pair<int, int>> res(n);
  function<void(int, int)> dfs = [&](int node, int fa) {
    int mini = inf, maxi = -inf;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
      mini = min(mini, res[ne].first);
      maxi = max(maxi, res[ne].second);
    }
    if (mini == inf) mini = maxi = ++cur;
    res[node] = {mini, maxi};
  };
  dfs(0, -1);
  for (auto& [l, r] : res) {
    cout << l << " " << r << "\n";
  }
}
