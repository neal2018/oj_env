#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX = 300000, MOD = 1e9 + 7;

ll power(ll a, ll b, ll p = MOD) {
  ll res = 1;
  for (a = a % p, b = b % (p - 1); b; b >>= 1, a = a * a % p) {
    if (b & 1) res = res * a % p;
  }
  return res;
}

int main(int argc, char const *argv[]) {
  ll n, t, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ll factor = power(2, n - 1);
    if (n % 2 == 1) {
      cout << power(factor + 1, k) << endl;
    } else {
      factor -= 1;
      ll res = 0, ff = 1;
      for (ll i = 0; i < k; i++) {
        res = (res + power(2, n * (k - i - 1)) % MOD * ff) % MOD;
        ff = (ff * factor) % MOD;
      }
      res = (res + power(factor, k)) % MOD;
      cout << res << endl;
    }
  }
  return 0;
}