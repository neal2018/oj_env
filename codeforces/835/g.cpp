#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> a >> b, a--, b--;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0, u, v, w; i < n - 1; i++) {
      cin >> u >> v >> w, u--, v--;
      g[u].push_back({v, w}), g[v].push_back({u, w});
    }
    if ([&] {
          function<bool(int, int, int)> dfs = [&](int node, int fa, int x) {
            if (node == a && x == 0) return true;
            for (auto& [ne, w] : g[node]) {
              if (ne == fa) continue;
              if (dfs(ne, node, x ^ w)) return true;
            }
            return false;
          };
          return dfs(b, -1, 0);
        }()) {
      cout << "YES\n";
      continue;
    }
    set<int> poss;
    function<void(int, int, int)> dfs_a = [&](int node, int fa, int x) {
      poss.insert(x);
      for (auto& [ne, w] : g[node]) {
        if (ne == fa || ne == b) continue;
        dfs_a(ne, node, x ^ w);
      }
    };
    dfs_a(a, -1, 0);

    function<bool(int, int, int)> dfs_b = [&](int node, int fa, int x) {
      if (node != b && poss.count(x)) return true;
      for (auto& [ne, w] : g[node]) {
        if (ne == fa) continue;
        if (dfs_b(ne, node, x ^ w)) return true;
      }
      return false;
    };
    if (dfs_b(b, -1, 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
