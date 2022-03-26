#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MOD = 998244353;

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

constexpr ll MAX_N = 1e5;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<Z> f(MAX_N, 1), rf(MAX_N, 1);
  for (int i = 2; i < MAX_N; i++) f[i] = f[i - 1] * i % MOD;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i = MAX_N - 2; i > 1; i--) rf[i] = rf[i + 1] * (i + 1) % MOD;
  auto binom = [&](int n, int r) -> Z {
    if (n < 0 || r < 0 || n < r) return 0;
    return f[n] * rf[n - r] * rf[r];
  };
  ll n, k;
  cin >> n >> k;
  vector<vector<Z>> dp(n, vector<Z>(k));
  for (int j = 0; j < k; j++) dp[0][j] = j + 1;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < k; j++) {
      for (int jj = 0; jj < k; jj++) {
        dp[i+1][max(jj, j)] += power(Z(jj+1), i);
      }
    }
  }
  cout << dp[n - 1][k - 1] << "\n";
}
