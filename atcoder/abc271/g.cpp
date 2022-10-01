#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://www.luogu.com.cn/problem/solution/P3306
// https://space.bilibili.com/672328094

ll power(ll a, ll b, ll MOD = 1, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}

ll inv(ll x, ll MOD) { return power(x, MOD - 2, MOD); }

ll bsgs(ll a, ll b, ll MOD) {
  a %= MOD, b %= MOD;
  map<ll, ll> map;
  ll m = ll(ceil(sqrt(MOD))), t = 1;
  for (int i = 0; i < m; ++i) {
    if (!map.count(t)) map[t] = i;
    t = t * a % MOD;
  }
  ll k = inv(t, MOD), w = b;
  for (int i = 0; i < m; ++i) {
    if (map.count(w)) return i * m + map[w];
    w = w * k % MOD;
  }
  return -1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a, b, p, x, t;
  cin >> T;
  while (T--) {
    cin >> p >> a >> b >> x >> t;
    if (x == t) {
      cout << 0 << '\n';
    } else if (a == 1) {
      t = ((t - x) % p + p) % p;
      if (t % gcd(b, p)) {
        cout << -1 << '\n';
      } else {
        if ((t * inv(b, p) + 1) % p == 0) {
          cout << p - 1 << '\n';
        } else {
          cout << (t * inv(b, p)) % p << '\n';
        }
      }
    } else if (a == 0) {
      cout << (b != t ? -1 : 1) << '\n';
    } else {
      ll ans = bsgs(a,
                    ((t - b * inv(1 - a, p)) % p + p) % p *
                        inv(((x - b * inv(1 - a, p)) % p + p) % p, p),
                    p) %
               p;
      cout << (ans == -1 ? -1 : ans) << '\n';
    }
  }
}
