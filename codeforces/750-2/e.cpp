#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, inf = 1e18;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    ll k = 0, res = 0;
    while (k * (k + 1) <= 2 * n) k++;
    vector dp(n + 1, vector<ll>(k));
    // dp[i][j]: after solve a[n-1-i]...a[n-1], the max of j length
    dp[n][0] = inf;
    for (ll i = n - 1; i >= 0; i--)
      for (ll j = 0; j < k; j++) {
        dp[i][j] = dp[i + 1][j];
        if (j && i + j <= n && pre[i + j] - pre[i] < dp[i + j][j - 1]) {
          dp[i][j] = max(dp[i][j], pre[i + j] - pre[i]);
          res = max(res, j);
        }
      }
    cout << res << '\n';
  }
}