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
  // auto operator<=>(const Z &) const = default;  // need c++ 20
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
  int n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  vector dp(2, vector(n + 1, vector(n + 1, Z(0))));
  for (int i = n; i >= 0; i--) {
    for (int j = n; j >= 0; j--) {
      if (i == n) {
        dp[0][i][j] = 1, dp[1][i][j] = 1;
        continue;
      }
      if (j == n) {
        dp[0][i][j] = 0, dp[1][i][j] = 0;
        continue;
      }
      for (int step = 1; step <= p; step++) {
        int arrive = min(n, i + step);
        dp[0][i][j] += dp[1][arrive][j];
      }
      dp[0][i][j] /= p;
      for (int step = 1; step <= q; step++) {
        int arrive = min(n, j + step);
        dp[1][i][j] += dp[0][i][arrive];
      }
      dp[1][i][j] /= q;
    }
  }
  cout << dp[0][a][b] << "\n";
}
