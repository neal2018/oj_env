#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ll MOD = 1e9 + 7;

ll norm(ll x) { return (x % MOD + MOD) % MOD; }
template <class T>
T power(T a, ll b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  auto operator<=>(const Z &) const = default;
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2); }
  Z &operator*=(const Z &rhs) { return x = x * rhs.x % MOD, *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const ll &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const ll &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll b, bd, bn, c, cd, cn;
    cin >> b >> bd >> bn >> c >> cd >> cn;
    if (cd % bd != 0) {
      cout << 0 << "\n";
      continue;
    }
    if ((c % bd + bd) % bd != (b % bd + bd) % bd) {
      cout << 0 << "\n";
      continue;
    }
    ll b_last = b + bd * (bn - 1);
    ll c_last = c + cd * (cn - 1);
    if (c < b || c_last > b_last) {
      cout << 0 << "\n";
      continue;
    }
    if (c - cd < b || c_last + cd > b_last) {
      cout << -1 << "\n";
      continue;
    }
    Z res = 0;
    auto add = [&](ll ad) {
      if (lcm(ad, bd) == cd) res += (cd / ad) * (cd / ad);
      // cd / ad ==  bd / gcd(bd, ad);
    };
    for (ll p = 1; p * p <= cd; p++) {
      if (cd % p == 0) {
        add(p);
        if (p * p != cd) {
          add(cd / p);
        }
      }
    }
    cout << res << "\n";
  }
}
