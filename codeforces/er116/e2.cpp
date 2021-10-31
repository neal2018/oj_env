#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
int main() {
  int n, x;
  cin >> n >> x;
  vector<ll> f(n + 1, 1), rf(n + 1, 1);
  for (int i = 2; i <= n; i++) f[i] = f[i - 1] * i % MOD;
  rf[n] = power(f[n], MOD - 2);
  for (int i = n - 1; i >= 2; i--) rf[i] = rf[i + 1] * (i + 1) % MOD;

  vector dp(n + 1, vector<ll>(x + 1));  // i people, at most x
  for (int i = 0; i <= x; i++) dp[0][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j <= x; j++) {
      for (int k = 0; k <= i; k++) {
        ll a = f[i] * rf[k] % MOD * rf[i - k] % MOD;
        ll b = power(i - 1, i - k);
        dp[i][j] += a * b % MOD * dp[k][j - (i - 1)] % MOD;
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[n][x] << '\n';
}