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
  vector<Z> f(MAX_N, 1), rf(MAX_N, 1);
  for (int i = 2; i < MAX_N; i++) f[i] = f[i - 1] * i;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i = MAX_N - 2; i > 1; i--) rf[i] = rf[i + 1] * (i + 1);
  auto binom = [&](int n, int r) -> Z {
    if (n < 0 || r < 0 || n < r) return 0;
    return f[n] * rf[n - r] * rf[r];
  };
  ll n;
  string s;
  cin >> n >> s;
  s += s;
  vector p(2 * n, vector<Z>(2 * n)), e(p);
  for (int i = 0; i < 2 * n - 1; i++) p[i][i + 1] = 1;
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i + l < 2 * n; i++) {
      int j = i + l;
      for (int k = i + 1; k < j; k++) {
        auto select = binom(l - 2, k - i - 1), total = (p[i][k] * p[k][j]) * select;
        auto sum = (s[i] == 'R') + (s[j] == 'L');
        p[i][j] += total * sum;
        e[i][j] += (e[i][k] * p[k][j] + e[k][j] * p[i][k]) * sum * select;
        e[i][j] += total * ((s[i] == 'R' ? k - i : 0) + (s[j] == 'L' ? j - k : 0));
      }
    }
  }
  Z res = 0;
  for (int i = 0; i < n; i++) res += e[i][n + i];
  res /= f[n];
  cout << res << "\n";
}