#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
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
  int n;
  string s;
  cin >> n >> s;
  vector dp(27, vector<Z>(27));
  dp[26][26] = 1;
  for (int i = 0; i < n; i++) {
    vector ndp(27, vector<Z>(27));
    if (s[i] != '?') {
      int c = s[i] - 'a';
      for (int ii = 0; ii < 27; ii++) {
        if (ii == c) continue;
        for (int jj = 0; jj < 27; jj++) {
          if (jj == c) continue;
          ndp[jj][c] += dp[ii][jj];
        }
      }
    } else {
      for (int ii = 0; ii < 27; ii++) {
        for (int jj = 0; jj < 27; jj++) {
          for (int c = 0; c < 26; c++) {
            if (c == ii || c == jj) continue;
            ndp[jj][c] += dp[ii][jj];
          }
        }
      }
    }
    swap(dp, ndp);
  }
  Z res = 0;
  for (auto &r : dp) {
    for (auto &x : r) res += x;
  }
  cout << res << "\n";
}
