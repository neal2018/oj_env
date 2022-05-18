#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

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
constexpr ll MAX_N = 251 * 251;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<Z> f(MAX_N, 1), rf(MAX_N, 1);
  for (int i = 2; i < MAX_N; i++) f[i] = f[i - 1] * i;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i = MAX_N - 2; i > 1; i--) rf[i] = rf[i + 1] * (i + 1);
  auto binom = [&](int n, int r) {
    if (n < 0 || r < 0 || n < r) return decltype(f)::value_type(0);
    return f[n] * rf[n - r] * rf[r];
  };
  int n;
  Z k;
  cin >> n >> k;
  Z res = 0;
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j <= n; j++) {
  //     Z tmp = binom(n, i) * binom(n, j) * power(Z(k - 1), n * n - i * j) * power(Z(k), i * j);
  //     tmp *= ((i + j) % 2) ? -1 : 1;
  //     res += tmp;
  //   }
  // }
  for (int i = 0; i <= n; i++) {
    Z tmp = binom(n, i) * power(power(k - 1, n) - power(k - 1, n - i) * power(k, i), n);
    tmp *= (i % 2) ? -1 : 1;
    res += tmp;
  }
  cout << res << "\n";
}
