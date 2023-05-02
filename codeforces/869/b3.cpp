#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
      deg[u]++, deg[v]++;
    }

    int good = 0;
    for (int i = 0; i < n; i++) {
      if (deg[i] < 4) continue;
      vector<int> stk, seen(n);
      function<void(int, int)> dfs = [&](int node, int fa) {
        if (good) return;
        if (node == i && stk.size() > 0) {
          auto path = stk;
          vector<array<int, 2>> res;

          for (auto& ne : g[i]) {
            auto it = find(path.begin(), path.end(), ne);
            if (it != path.begin() + 1 && it != path.end()) {
              path.erase(it + 1, path.end());
            }
          }

          int need = 0;
          for (auto& ne : g[i]) {
            auto it = find(path.begin(), path.end(), ne);
            if (it == path.end()) res.push_back({i, ne}), need++;
            if (need == 2) break;
          }

          for (int ii = 0; ii < path.size(); ii++) {
            res.push_back({path[ii], path[(ii + 1) % path.size()]});
          }
          cout << "YES\n";
          cout << res.size() << "\n";
          for (auto& [x, y] : res) cout << x + 1 << " " << y + 1 << "\n";
          good = 1;
          return;
        }
        if (seen[node]) return;
        seen[node] = 1;
        stk.push_back(node);
        for (auto& ne : g[node]) {
          if (ne == fa) continue;
          dfs(ne, node);
        }
        stk.pop_back();
      };
      dfs(i, -1);
    }
    if (!good) cout << "NO\n";
  }
}
