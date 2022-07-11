#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b, ll MOD = 998244353, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}

ll BSGS(ll a, ll n, ll p, ll ad) {
  map<ll, ll> map;
  ll m = ll(sqrt(p)) + 1, t = 1;
  for (ll i = 0; i < m; i++, t = t * a % p) map[t * n % p] = i;
  for (ll i = 0, tmp = t, s = ad; i <= m; i++, s = s * tmp % p) {
    if (map.count(s) == 0) continue;
    if (i * m - map[s] >= 0) return i * m - map[s];
  }
  return -1;
}

ll exBSGS(ll a, ll n, ll p) {
  a %= p, n %= p;
  if (n == 1 || p == 1) return 0;
  ll cnt = 0, d, ad = 1;
  while ((d = gcd(a, p)) > 1) {
    if (n % d) return -1;
    cnt++, n /= d, p /= d;
    ad = (ad * a / d) % p;
    if (ad == n) return cnt;
  }
  ll ans = BSGS(a, n, p, ad);
  if (ans == -1) return -1;
  return ans + cnt;
}

int read() {
  int x;
  cin >> x;
  return x;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << ([&] {
    ll a, b, m, x0, x;
    cin >> a >> b >> m >> x0 >> x;
    if (x == x0) return true;
    if (a == 0) return b == x;
    if (a == 1) return b != 0;
    ll aa = power(a - 1, m - 2, m);
    ll A = x + b * aa, B = x0 + b * aa;
    ll t = (A % m) * power(B % m, m - 2, m) % m;
    auto res = exBSGS(a, t, m);
    return res != -1;
  }()
               ? "YES\n"
               : "NO\n");
}
