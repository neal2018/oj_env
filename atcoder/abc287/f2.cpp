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
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> sz(n);

  vector dp(2, vector(n, vector<Z>(n + 1)));
  for (int i = 0; i < n; i++) dp[1][i][1] = 1, dp[0][i][0] = 1;
  function<void(int, int)> dfs = [&](int node, int fa) {
    sz[node] = 1;
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
      for (int j = sz[node]; j >= 0; j--) {
        for (int k = min(sz[ne], n - j); k >= 1; k--) {
          dp[0][node][j + k] += dp[0][node][j] * dp[0][ne][k] + dp[0][node][j] * dp[1][ne][k];
          dp[1][node][j + k] += dp[1][node][j] * dp[0][ne][k];
          dp[1][node][j + k - 1] += dp[1][node][j] * dp[1][ne][k];
        }
      }
      sz[node] += sz[ne];
    }
  };
  dfs(0, -1);
  for (int i = 1; i <= n; i++) {
    cout << (dp[0][0][i] + dp[1][0][i]) << "\n";
  }
}
