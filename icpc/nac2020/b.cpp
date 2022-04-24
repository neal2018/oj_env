#include <bits/stdc++.h> 
using namespace std;

#define FOR(x,n) for(int x=0;x<n;x++)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using vi = vector<int>;
const char nl = '\n';
const ll MOD = 998244353;

template <typename T>
constexpr T power(T a, ll b, T res = 1) {
  for(; b; b/=2, (a *=a) %= MOD) {
    if( b &1) (res *= a) %= MOD;
  }
  return res;
}
const int MAX_N = 1e6+10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  vi min_p(MAX_N), mu(MAX_N), primes;
  mu[1] = 1, primes.reserve(1e6+10);
  for(int i = 2; i < MAX_N; i++) {
    if(min_p[i] == 0) {
      min_p[i] = i;
      primes.push_back(i);
      mu[i] = -1;
    }
    for(auto p : primes) { 
      if(i * p >= MAX_N) break;
      min_p[i*p] = p;
      if(i % p == 0) {
        mu[i*p] = 0;
        break;
      }
      mu [i*p] = -mu[i];
    }
  }

  int n,m;
  cin >> n >> m;
  ll ans = 0;

  for(int i = 1; i <= 1000000; i++) {
    if(mu[i] == 0) continue;
    ll possible = m/i;
    possible = possible * 2 + 1;
    ll multi = power(possible, n);
    multi--;
    multi = (multi + MOD) % MOD;
    ans += multi * mu[i];
    ans = (ans+MOD) % MOD;
  }
  ans++;
  ans %= MOD;
  cout << ans << nl;

}