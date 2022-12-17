#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  function<int(int, int)> dfs = [&](int node, int fa) {
    int res = 0;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      res = max(res, dfs(ne, node));
    }
    return res + 1;
  };
  int res = 0;
  for (auto& ne : g[0]) {
    res += dfs(ne, 0);
  }
  cout << res << "\n";
}
