#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), pre(n + 1);
  for (auto& x : a) cin >> x;
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
  vector dp(n + 1, vector<ll>(m + 1, 1e18));
  dp[0][0] = 0;
  for (ll k = m; k >= 0; k--) {
    for (ll j = 0; j <= m - k; j++) {
      for (ll i = 0; i < n && i * k <= j; i++) {
        dp[i + 1][j + k] = min(dp[i + 1][j + k], dp[i][j] + abs(j - pre[i]));
      }
    }
  }
  cout << dp[n][m] << "\n";
}
