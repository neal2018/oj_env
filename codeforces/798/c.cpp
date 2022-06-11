#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    int one = inf, leaf = inf;
    function<void(int, int, int)> dfs = [&](int node, int fa, int dep) {
      int cnt = 0;
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        cnt++;
        dfs(ne, node, dep + 1);
      }
      if (cnt == 0) leaf = min(leaf, dep);
      if (cnt == 1) one = min(one, dep);
    };
    dfs(0, -1, 0);
    cout << max(n - 2 * one - 2, n - 2 * leaf - 1) << "\n";
  }
}
