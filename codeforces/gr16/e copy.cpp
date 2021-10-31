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
    ll res = 0;
    function<int(int, int)> dfs = [&](int node, int fa) {
      ll cnt = 0;
      for (auto& ne : g[node]) if (ne != fa) cnt += dfs(ne, node);
      if (!cnt) return 1;
      res += cnt - 1;
      return 0;
    };
    dfs(0, -1);
    cout << res + 1 << '\n';
  }
}