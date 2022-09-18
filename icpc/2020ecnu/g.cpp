#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
template <typename T>
T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  static int norm(int x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
  }
  auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
  Z &operator*=(const Z &rhs) { return x = int(ll(x) * rhs.x % MOD), *this; }
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

struct Rational {
  ll x, y;
  void norm() {
    if (x == 0) y = 1;
    auto g = gcd(x, y);
    x /= g, y /= g;
    if (y < 0) x = -x, y = -y;
  }
  Rational(ll _x, ll _y) : x(_x), y(_y) { norm(); }
  Rational(ll _x) : x(_x), y(1) { norm(); }
  friend Rational operator+(Rational lhs, const Rational &rhs) {
    auto x = lhs.x * rhs.y + rhs.x * lhs.y;
    auto y = lhs.y * rhs.y;
    return Rational(x, y);
  }
  friend Rational operator-(Rational lhs, const Rational &rhs) {
    auto x = lhs.x * rhs.y - rhs.x * lhs.y;
    auto y = lhs.y * rhs.y;
    return Rational(x, y);
  }
  friend Rational operator*(Rational lhs, const Rational &rhs) {
    auto x = lhs.x * rhs.x;
    auto y = lhs.y * rhs.y;
    return Rational(x, y);
  }
  friend Rational operator/(Rational lhs, const Rational &rhs) {
    auto x = lhs.x * rhs.y;
    auto y = lhs.y * rhs.x;
    return Rational(x, y);
  }
  friend Rational operator<(Rational lhs, const Rational &rhs) { return (lhs - rhs).x < 0; }
  friend Rational operator==(Rational lhs, const Rational &rhs) { return (lhs - rhs).x == 0; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int ag, dg, ac, dc;
    int n, m, a, b;
    cin >> ag >> dg >> ac >> dc >> n >> m >> a >> b;
  }
}
