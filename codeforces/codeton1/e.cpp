#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> res(n), deg(n), sum(n);
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
      deg[u]++, deg[v]++;
    }
    function<void(int, int, int)> dfs = [&](int node, int fa, int dep) {
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        dfs(ne, node, dep + 1);
        sum[node] += sum[ne];
      }
      if (dep == 0) {
        res[node] = -sum[node];
        sum[node] = 0;
      } else if (dep % 2 == 0) {
        res[node] = 1 - sum[node];
        sum[node] = 1;
      } else {
        res[node] = -1 - sum[node];
        sum[node] = -1;
      }
    };
    dfs(0, -1, 0);
    for (auto& x : res) cout << x << ' ';
    cout << "\n";
  }
}
