#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr ll MOD = 998244353;

ll norm(ll x) { return (x + MOD) % MOD; }
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
  Z n, all_bw = 1, all_wb = 1, extra = 1, w = 0, b = 0;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s[0] == 'W' || s[1] == 'B') all_bw = 0;
    if (s[0] == 'B' || s[1] == 'W') all_wb = 0;
    if (s == "??") extra *= 2;
    if (s == "WW" || s == "BB") extra = 0;
    w += count(s.begin(), s.end(), 'W');
    b += count(s.begin(), s.end(), 'B');
  }
  Z res;
  function<Z(Z)> f = [&](Z x) { return x <= 1 ? 1 : x * f(x - 1); };
  if (w > n || b > n) {
    res = 0;
  } else {
    res = f(2 * n - w - b) / f(n - w) / f(n - b) - extra + all_wb + all_bw;
  }
  cout << res << '\n';
}