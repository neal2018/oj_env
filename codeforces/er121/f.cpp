#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
constexpr ll MOD = 998244353;

constexpr ll norm(ll x) { return (x % MOD + MOD) % MOD; }
template <class T>
constexpr T power(T a, ll b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  ll x;
  constexpr Z(ll _x = 0) : x(norm(_x)) {}
  constexpr auto operator<=>(const Z &) const = default;
  constexpr Z operator-() const { return Z(norm(MOD - x)); }
  constexpr Z inv() const { return power(*this, MOD - 2); }
  constexpr Z &operator*=(const Z &rhs) { return x = x * rhs.x % MOD, *this; }
  constexpr Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  constexpr Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  constexpr Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  constexpr Z &operator%=(const ll &rhs) { return x %= rhs, *this; }
  constexpr friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  constexpr friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  constexpr friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  constexpr friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  constexpr friend Z operator%(Z lhs, const ll &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

constexpr int LCM = 720720;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, a, xx, yy, k, m;
  cin >> n >> a >> xx >> yy >> k >> m;
  vector<Z> dp(LCM + 1);
  Z inv_n = Z(1) / n;
  for (ll i = k; i >= 1; i--) {
    for (ll j = LCM; j >= 0; j--) {
      dp[j] = ((n - 1) * dp[j] + dp[j - j % i] + j) * inv_n;
    }
  }
  Z res = 0;
  for (int i = 0; i < n; i++) {
    res += Z(k) * (Z(a) - (a % LCM)) * inv_n + dp[a % LCM];
    a = (a * xx + yy) % m;
  }
  res *= power(Z(n), k);
  cout << res.x << "\n";
}
