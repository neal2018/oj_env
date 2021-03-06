#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

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

constexpr ll MAX_N = 3e5;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<Z> f(MAX_N, 1), rf(MAX_N, 1);
  for (int i : views::iota(2, MAX_N)) f[i] = f[i - 1] * i % MOD;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i : views::iota(2, MAX_N - 1) | views::reverse) rf[i] = rf[i + 1] * (i + 1) % MOD;
  auto binom = [&](ll n, ll r) -> Z {
    if (n < 0 || r < 0 || n < r) return 0;
    return f[n] * rf[n - r] * rf[r];
  };

  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  Z res = 0;
  function<int(int, int)> dfs = [&](int node, int fa) {
    vector<int> sub;
    Z sum = 0;
    int sz = 1;
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      int sub_sz = dfs(ne, node);
      sub.push_back(sub_sz);
      sz += sub_sz, sum += binom(sub_sz, k);
    }
    if (node != 0) sub.push_back(n - sz), sum += binom(n - sz, k);
    for (auto &sub_sz : sub) {
      res += (binom(n - sub_sz, k) - sum + binom(sub_sz, k)) * (n - sub_sz) * sub_sz;
    }
    res += (binom(n, k) - sum) * n;
    return sz;
  };
  dfs(0, -1);
  cout << res << "\n";
}
