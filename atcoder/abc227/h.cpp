#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
constexpr int MAX_N = 60;

ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<ll> f(MAX_N, 1), rf(MAX_N, 1);
  for (int i = 2; i < MAX_N; i++) f[i] = f[i - 1] * i % MOD;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i = MAX_N - 2; i > 1; i--) rf[i] = rf[i + 1] * (i + 1) % MOD;
  vector<map<ll, ll>> dp(n + 1);
  dp[0][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      // add j-i
      for (auto& [l, x] : dp[i]) {
        ll add = x * f[n - i - 1] % MOD * rf[n - j] % MOD;
        (dp[j][lcm(l, j - i)] += add) %= MOD;
      }
    }
  }
  ll res = 0;
  for (auto& [l, x] : dp[n]) (res += power(l, k) * x % MOD) %= MOD;
  cout << res << '\n';
}