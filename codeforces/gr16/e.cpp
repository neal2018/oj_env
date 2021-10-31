#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n, u, v;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      g[u - 1].push_back(v - 1);
      g[v - 1].push_back(u - 1);
    }
    ll res = 0, has = 0, bud = 0;
    function<pair<bool, bool>(int, int)> dfs = [&](int node, int fa) {
      // is leaf
      bool allleaf = true, isleaf = true;
      ll cnt = 0, budcnt = 0;
      for (auto& ne : g[node]) {
        if (ne != fa) {
          auto [c1, c2] = dfs(ne, node);
          if (!c2) {
            if (c1) {
              cnt++;
            }
            isleaf = false;
          }
        }
      }
      if (isleaf) return pair{true, false};
      if (node != 0 && allleaf) {
        res += cnt - 1;
        return pair{false, true};
      } else {
        has += cnt;
      }
      return pair{false, false};
    };
    dfs(0, -1);
    cout << res + max(has, 1LL) << '\n';
  }
}