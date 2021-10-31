#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
ll MOD = 998244353;

ll qpow(ll a, ll b) {
  ll res = 1;
  for (; b > 0; b /= 2) {
    if (b & 1) (res *= a) %= MOD;
    (a *= a) %= MOD;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, D;
  cin >> n >> D;
  ll d = D;
  ll res = 0;
  ll t = (qpow(2, d) + ((d - 1) * qpow(2, d - 2)) % MOD) % MOD;
  for (ll i = 0; i < n; i++) {
    ll remain = n - 1 - i;
    if (remain >= D) {
      res = (res + (t * qpow(2, i))%MOD) % MOD;
    } else if (remain >= D / 2) {
      res = (res + ((2 * remain - d + 1) * qpow(2, d - 2)) % MOD * qpow(2, i) % MOD) % MOD;
    }
  }
  cout << (res * 2) % MOD << '\n';
}