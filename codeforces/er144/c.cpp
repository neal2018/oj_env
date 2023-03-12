#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
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
  int T;
  cin >> T;
  // constexpr int MAX_N = 1e6 + 10, MAX_LEN = 21;
  // vector<vector<Z>> memo(MAX_N, vector<Z>(MAX_LEN, -1));
  while (T--) {
    ll l, r;
    cin >> l >> r;
    // l = 1000000 / 4 + 1, r = 1000000;
    auto cnt = [&] {
      ll res = 1;
      ll x = l;
      while (2 * x <= r) {
        x *= 2, res++;
      }
      return res;
    }();
    cout << cnt << " ";
    ll mul = (1 << (cnt - 1));
    if (cnt == 1) {
      cout << r - l + 1 << "\n";
      continue;
    }
    Z res = r / mul - l + 1;
    if (mul % 2 == 0) {
      ll mul_three = mul / 2 * 3;
      if (l * mul_three <= r) {
        res += (r / mul_three - l + 1) * (cnt - 1);
      }
    }
    cout << res << "\n";
  }
}
