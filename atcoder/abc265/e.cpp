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
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> move(3);
  for (auto &[x, y] : move) cin >> x >> y;
  set<pair<ll, ll>> st;
  vector<pair<ll, ll>> block(m);
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y, st.insert({x, y});
  }
  vector<vector<Z>> dp(n + 1, vector<Z>(n + 1));
  dp[0][0] = 1;
  for (int step = 0; step < n; step++) {
    vector<vector<Z>> ndp(n + 1, vector<Z>(n + 1));
    for (int i = 0; i <= step; i++) {
      for (int j = 0; i + j <= step; j++) {
        ll x = move[0].first * i + move[1].first * j + move[2].first * (step - i - j);
        ll y = move[0].second * i + move[1].second * j + move[2].second * (step - i - j);
        for (int k = 0; k < 3; k++) {
          ll xx = x + move[k].first, yy = y + move[k].second;
          if (!st.count({xx, yy})) {
            ndp[i + (k == 0)][j + (k == 1)] += dp[i][j];
          }
        }
      }
    }
    swap(dp, ndp);
  }
  Z res = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      res += dp[i][j];
    }
  }
  cout << res << "\n";
}
