#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

constexpr ll MAX_N = 1e4;

int main() {
  // from https://www.acwing.com/file_system/file/content/whole/index/content/4065442/
  ll n, m;
  cin >> n >> m;
  vector<Z> d(1 << n), c(n), a(n);
  vector<ll> p(1 << n), b(n);
  d[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    b[i]++;
    Z x = -power(a[i], b[i]);
    for (int j = 0; j < (1 << i); j++) {
      d[(1 << i) + j] = d[j] * x;
      p[(1 << i) + j] = p[j] + b[i];
    }
  }
  for (int i = 0; i < n; i++) {
    Z x = 1 / a[i], y = 1;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        y *= (1 - a[j] * x);
      }
    }
    c[i] = 1 / y;
  }
  Z res = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (p[i] <= m) {
      for (int j = 0; j < n; j++) {
        res += d[i] * power(a[j], m - p[i]) * c[j];
      }
    }
  }
  cout << res << "\n";
}
