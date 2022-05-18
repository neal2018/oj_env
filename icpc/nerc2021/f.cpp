#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const int MX = 5005;
ll fact[MX], factinv[MX];

template<typename T>
constexpr T power(T a, ll b, T res = 1) {
  for(; b; b /= 2, (a *= a) %= MOD)
    if(b & 1) (res *= a) %= MOD;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  fact[0] = 1, factinv[0] = 1;
  for(ll i = 1; i < MX; i++) {
    fact[i] = (i * fact[i - 1]) % MOD;
    factinv[i] = power(fact[i], MOD - 2);
  }

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n), consider(n), distinct(n);
    map<int,int> ct;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      ct[a[i]]++;
    }

    for(int i = 0; i < n; i++) {
      if(i == 0 || a[i] != a[i - 1]) {
        consider[i]++;
        distinct[i] = ct[a[i]];
      }
    }

    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int i = 0; i < n; i++) if(consider[i]) dp[0][i] = distinct[i];
    for(int i = 1; i < n; i++) {
      if(i & 1) {
        ll contr = 0;
        for(int j = 0; j < n; j++) {
          if(consider[j]) {
            dp[i][j] = contr;
            dp[i][j] = (dp[i][j] * (distinct[j])) % MOD;
          }
          contr = (contr + dp[i - 1][j]) % MOD;
        }
      }
      else {
        for(int j = 0; j < n; j++) {
          if(j + i - 1 <= 0) continue;
          dp[i][j] = ((ll)(j + 1 - i) * dp[i - 1][j]) % MOD;
        }
      }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans = (ans + dp[n - 1][i]) % MOD;
    for(auto [v, c] : ct) ans = (ans * factinv[c]) % MOD; 
    cout << ans << '\n';
  }
}