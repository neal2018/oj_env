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
  vector<int> res;

  function<void(int, int, int)> dfs = [&](int node, int fa, int color) {
    if (color == 1) {
      res.push_back(g[node].size());
    }
    color = (color + 1) % 3;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node, color);
    }
  };

  for (int i = 0; i < n; i++) {
    if (g[i].size() == 1) {
      dfs(i, -1, 0);
      break;
    }
  }

  sort(res.begin(), res.end());
  for (auto& x : res) cout << x << " ";
  cout << "\n";
}
