#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, l, k;
  cin >> n >> l >> k;
  vector<ll> v, d(n), a(n);
  for (auto& x : d) cin >> x;
  for (auto& x : a) cin >> x;
  d.push_back(l);
  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1e18));
  for (int i = 0; i <= k; i++) dp[0][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      // handle #i, remain j to cut
      for (int t = 0; t <= min(j, i - 1); t++) {
        // cut t, not cut #i
        dp[i][j] = min(dp[i][j], dp[i - t - 1][j - t] + (d[i] - d[i - t - 1]) * a[i - t - 1]);
      }
    }
  }
  ll res = 1e18;
  for (int i = 0; i <= k; i++) res = min(res, dp[n][i]);
  cout << res << "\n";
}