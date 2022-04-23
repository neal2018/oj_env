#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

constexpr ll power(ll a, ll b, ll mod, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= mod)
    if (b & 1) (res *= a) %= mod;
  return res;
}

const ll MOD = 1e9 + 9;

int main() {
  int n;
  cin >> n; 
  vector<ll> inverse(n + 1);
  for(int i = 1; i <= n; i++) inverse[i] = power(i, MOD - 2, MOD);
  vector<int> arr(n + 1);
  for(int i = 0; i < n; i++) cin >> arr[i + 1];
  sort(arr.begin() + 1, arr.end());
  
  ll dp[n + 1][n + 1][2];
  memset(dp, 0, sizeof dp);
  dp[0][0][0] = 1;
  for(int i = 0; i < n; i++) {
    ll inside = 0, num_seek = 0;
    for(int j = i; j >= 0; j--) {
      inside++;
      if(arr[j + 1] == arr[i + 1]) num_seek++;
      for(int k = 0; k < 2; k++) {
        // PUT THIS IN
        dp[i + 1][i + 1][k ^ 1] = (dp[i + 1][i + 1][k ^ 1] + dp[i][j][k]) % MOD;
        // DON'T
        ll inc = (dp[i][j][k] * inside) % MOD;
        inc = (inc * inverse[num_seek]) % MOD;
        dp[i + 1][j][k] = (dp[i + 1][j][k] + inc) % MOD;
      }
    }
  }

  ll ans = 0;
  for(int j = 0; j <= n; j++) {
    ans = (ans + dp[n][j][0]) % MOD;
    ans = (ans - dp[n][j][1] + MOD) % MOD;
  }
  cout << ans << '\n';
}