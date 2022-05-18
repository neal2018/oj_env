#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

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

constexpr int SZ = 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector g(SZ, vector<int>(SZ));
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    g[u][v] = 1, g[v][u] = 1;
  }
  vector to(1 << SZ, vector<int>(SZ, -1));
  for (int mask = 0; mask < (1 << SZ); mask++) {
    for (int i = 0; i < SZ; i++) {
      int f = 1;
      for (int t = 0; t < SZ && f; t++) {
        if (mask & (1 << t) && i > t && g[i][t]) f = 0;
      }
      if (!f) continue;
      int n_mask = (1 << i);
      for (int j = 0; j < SZ; j++) {
        if (g[i][j] && (mask & (1 << j))) n_mask |= (1 << j);
      }
      to[mask][i] = n_mask;
    }
  }
  vector<Z> dp(1 << SZ);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<Z> n_dp(1 << SZ);
    for (int mask = 0; mask < (1 << SZ); mask++) {
      for (int c = 0; c < SZ; c++) {
        if (to[mask][c] != -1) {
          n_dp[to[mask][c]] += dp[mask];
        }
      }
    }
    swap(dp, n_dp);
  }
  cout << accumulate(dp.begin(), dp.end(), Z(0)) << "\n";
}
