#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<vector<ll>> dp(n, vector<ll>(n + 1));
  vector<int> mark(n + 1);
  function<int(int, int)> dfs = [&](int node, int fa) {
    int sz = 1;
    dp[node][1] = 1;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      int sub = dfs(ne, node);
      for (int i = sz; i; i--) {
        for (int j = 1; j <= sub && i + j <= n; j++) {
          __int128 t = dp[node][i + j] + (__int128)dp[node][i] * dp[ne][j];
          if (t >= k) mark[i + j] = 1;
          dp[node][i + j] = dp[node][i + j] + dp[node][i] * dp[ne][j];
        }
      }
      sz += sub;
    }
    return sz;
  };
  dfs(0, -1);
  vector<ll> sum(n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) sum[j] += dp[i][j];
  }
  // for (auto& x : sum) cout << x << ' ';
  // cout << "\n";
  __int128 cur = 0;
  for (int i = 0; i <= n; i++) {
    cur += sum[i];
    if (cur >= k || mark[i]) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << "-1\n";
}