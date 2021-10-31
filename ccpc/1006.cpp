#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  string s;
  cin >> T;
  while (T--) {
    cin >> s;
    // dp[i][j]
    ll n = s.size();
    vector<ll> dp(10);
    vector<ll> suffix(n);
    suffix[n - 1] = (s[n - 1] == 'a' ? 1 : 0);
    for (int i = n - 2; i >= 0; i--) {
      suffix[i] = (s[i] == 'a' ? 1 : 0) + suffix[i + 1];
    }
    for (int i = 0; i < n; i++) {
      vector<ll> nex_dp = dp;
      if (s[i] == 'n') {
        (nex_dp[0] += 1) %= MOD;
        (nex_dp[2] += dp[1]) %= MOD;
      } else if (s[i] == 'u') {
        (nex_dp[1] += dp[0]) %= MOD;
      } else if (s[i] == 'h') {
        (nex_dp[3] += dp[2]) %= MOD;
        (nex_dp[5] += dp[4]) %= MOD;
        (nex_dp[6] += dp[5]) %= MOD;
        (nex_dp[8] += dp[7]) %= MOD;
      } else if (s[i] == 'e') {
        (nex_dp[4] += dp[3]) %= MOD;
        (nex_dp[7] += dp[6]) %= MOD;
      } else if (s[i] == 'a') {
        (nex_dp[9] += (dp[8] + nex_dp[9]) % MOD) %= MOD;
      }
      dp = nex_dp;
    }
    cout << dp[9] << '\n';
  }
}