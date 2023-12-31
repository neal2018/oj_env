#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
int power(int, ll) = delete;
template <typename T>
T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  Z(long long _x) : x(norm(int((_x % MOD + MOD) % MOD))) {}
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto ask = [&](ll x) {
    // # < x
    auto get_g = [](ll xx) {
      const auto f = __lg(xx);
      ll res = 1, t = f;
      while (__int128(t) * f <= xx) {
        t *= f;
        res++;
      }
      return res;
    };

    Z res = 0;
    for (int bit = 2; bit < 61; bit++) {
      ll start = 1ll << bit, end = 2 * start;
      const auto f = __lg(start);
      ll g = get_g(start);
      ll last_g = get_g(end - 1);
      if (g == last_g) {
        if (x <= end) {
          res += (x - start) * g % MOD;
          break;
        }
        res += (end - start) * g % MOD;
      } else {
        ll t = 1;
        for (int _ = 0; _ < g + 1; _++) t *= f;
        const auto start2 = t;
        if (x <= start2) {
          res += (x - start) * g % MOD;
          break;
        }
        res += (start2 - start) * g % MOD;
        if (x <= end) {
          res += (x - start2) * last_g % MOD;
          break;
        }
        res += (end - start2) * last_g % MOD;
      }
    }
    return res;
  };
  int q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << ask(r + 1) - ask(l) << "\n";
  }
}
