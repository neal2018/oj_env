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
  // auto operator<=>(const Z &) const = default;
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
  Z res = 0;
  ll n, m, k, x1, x2, y1, y2, MAX = 1e6 + 10;
  cin >> n >> m >> k >> x1 >> y1 >> x2 >> y2;
  vector<Z> f(MAX, 1);
  for (int i = 2; i < MAX; i++) f[i] *= f[i - 1] * i;
  vector<Z> hh(MAX), hi(MAX), ww(MAX), wi(MAX);
  hi[0] = 1, wi[0] = 1;
  for (int i = 1; i < MAX; i++) {
    hi[i] = (n - 1) * hh[i - 1];
    wi[i] = (m - 1) * ww[i - 1];
    hh[i] = hi[i - 1] + (n - 2) * hh[i - 1];
    ww[i] = wi[i - 1] + (m - 2) * ww[i - 1];
  }
  for (int i = 0; i <= k; i++) {
    Z p1 = (x1 == x2 ? hi[i] : hh[i]);
    Z p2 = (y1 == y2 ? wi[k - i] : ww[k - i]);
    res += p1 * p2 * f[k] / f[i] / f[k - i];
  }
  cout << res << '\n';
}