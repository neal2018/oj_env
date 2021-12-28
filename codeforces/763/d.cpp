#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
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
  ll T;
  cin >> T;
  for (; T--;) {
    Z n, m, rb, cb, rd, cd, p;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    rb -= 1, cb -= 1, rd -= 1, cd -= 1, p /= 100;
    Z dx = -1, dy = -1, x = rb, y = cb, a = 0, b = 1;
    if (!(0 <= x + dx && x + dx < n)) dx = -dx;
    if (!(0 <= y + dy && y + dy < m)) dy = -dy;
    Z dx0 = dx, dy0 = dy;
    while (true) {
      x += dx, y += dy;
      if (x == rd || y == cd) {
        a = (a + 1) * (1 - p), b *= (1 - p);
      } else {
        a += 1;
      }
      // change direction
      if (!(0 <= x + dx && x + dx < n)) dx = -dx;
      if (!(0 <= y + dy && y + dy < m)) dy = -dy;
      if (x == rb && y == cb && dx == dx0 && dy == dy0) break;
    }
    cout << a / (1 - b) << "\n";
  }
}