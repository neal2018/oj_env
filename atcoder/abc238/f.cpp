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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) cin >> x, x--;
  for (auto &[x, y] : a) cin >> y, y--;
  sort(a.begin(), a.end());
  vector dp(k + 1, vector<Z>(n + 1));
  dp[0][n] = 1;
  for (auto &[x, i] : a) {
    vector ndp(k + 1, vector<Z>(n + 1));
    for (int j = 0; j <= k; j++) {
      for (int ii = 0; ii <= n; ii++) {
        if (i < ii && j < k) ndp[j + 1][ii] += dp[j][ii];
        ndp[j][min(ii, i)] += dp[j][ii];
      }
    }
    dp = ndp;
  }
  cout << accumulate(dp[k].begin(), dp[k].end(), Z(0)) << "\n";
}
