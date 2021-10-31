#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr ll MOD = 998244353;
ll power(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
ll inv(ll a, ll m) { return a == 1 ? 1 : ((m - m / a) * inv(m % a, m) % m); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, X;
  cin >> N >> X;
  int MAX = N + 10;
  vector<ll> f(MAX, 1);
  vector<ll> rf(MAX, 1);
  for (int i = 1; i < MAX; ++i) {
    f[i] = (f[i - 1] * i) % MOD;
    rf[i] = (rf[i - 1] * inv(i, MOD)) % MOD;
  }
  vector dp(N + 1, vector<ll>(X + 1));  // d[i][j], i people, all less than x, one winner
  for (int x = 1; x <= X; x++) dp[1][x] = x;
  for (int n = 2; n <= N; n++) {
    for (int x = n - 1; x <= X; x++) {
      for (int alive = 1; alive <= n; alive++) {
        ll choose_alive = f[n] * rf[n - alive] % MOD * rf[alive] % MOD;
        ll dead_ways = power(n - 1, n - alive);
        (dp[n][x] += choose_alive * dead_ways % MOD * dp[alive][x - (n - 1)] % MOD) %= MOD;
      }
    }
  }
  cout << (power(X, N) + MOD - dp[N][X]) % MOD << '\n';
}