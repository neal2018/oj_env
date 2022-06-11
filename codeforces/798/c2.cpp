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
    int res = 0;
    function<void(int, int, int, int)> dfs = [&](int node, int fa, int dep, int need) {
      int cnt = 0;
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        cnt++;
      }
      if (need + cnt <= dep + 1) {
        res = max(res, n - (need + cnt) - (dep + 1));
      }
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        dfs(ne, node, dep + 1, need + max(0, cnt - 1));
      }
    };
    dfs(0, -1, 0, 0);
    cout << res << "\n";
  }
}
