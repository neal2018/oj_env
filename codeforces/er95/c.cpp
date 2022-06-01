#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n), dp(n + 1), dp2(n + 1);  // me, friend
    for (auto& x : a) cin >> x;
    dp2[0] = 1e9;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        dp[i + 1] = min(dp2[i], dp2[i - 1]);
        dp2[i + 1] = min(dp[i] + a[i], dp[i - 1] + (a[i] + a[i - 1]));
      } else {
        dp[i + 1] = dp2[i];
        dp2[i + 1] = dp[i] + a[i];
      }
    }
    cout << min(dp.back(), dp2.back()) << "\n";
  }
}
