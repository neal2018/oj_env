#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;
template <typename T>
T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  static ll norm(ll x) { return (x % MOD + MOD) % MOD; }
  // auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
  Z &operator*=(const Z &rhs) { return x = ll(ll(x) * rhs.x % MOD), *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const int &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const int &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, q;
  cin >> n >> m >> q;
  while (q--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, c--;
    Z res = 0;
    if ((a + c) % 2 == 0) {
      {
        ll len = (d - c + 1) / 2;
        ll len2 = (b - a + 1) / 2;
        if (len && len2) {
          Z t = a * m + c + 1;
          Z first = Z(t + (t + (len - 1) * 2)) * len / 2;
          Z cur = (first + (first + Z(len2 - 1) * len * 2 * m)) * len2 / 2;
          res += cur;
        }
      }
      {
        ll len = (d - c) / 2;
        ll len2 = (b - a) / 2;
        if (len && len2) {
          Z t = (a + 1) * m + (c + 1) + 1;
          Z first = Z(t + (t + (len - 1) * 2)) * len / 2;
          Z cur = (first + (first + Z(len2 - 1) * len * 2 * m)) * len2 / 2;
          res += cur;
        }
      }
    } else {
      {
        ll len = (d - c) / 2;
        ll len2 = (b - a + 1) / 2;
        if (len && len2) {
          Z t = a * m + (c + 1) + 1;
          Z first = Z(t + (t + (len - 1) * 2)) * len / 2;
          Z cur = (first + (first + Z(len2 - 1) * len * 2 * m)) * len2 / 2;
          res += cur;
        }
      }
      {
        ll len = (d - c + 1) / 2;
        ll len2 = (b - a) / 2;
        if (len && len2) {
          Z t = (a + 1) * m + c + 1;
          Z first = Z(t + (t + (len - 1) * 2)) * len / 2;
          Z cur = (first + (first + Z(len2 - 1) * len * 2 * m)) * len2 / 2;
          res += cur;
        }
      }
    }
    cout << res << "\n";
  }
}
