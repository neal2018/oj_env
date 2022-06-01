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
  for (int i = 2; i < MAX_N; i++) f[i] = f[i - 1] * i % MOD;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i = MAX_N - 2; i > 1; i--) rf[i] = rf[i + 1] * (i + 1) % MOD;
  auto binom = [&](ll n, ll r) -> Z {
    if (n < 0 || r < 0 || n < r) return 0;
    return f[n] * rf[n - r] * rf[r];
  };
  int n, k;
  cin >> n >> k;
  vector<vector<ll>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> sz(n, 1);
  vector<Z> subtree(n);
  function<void(int, int)> dfs = [&](int node, int fa) {
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
      sz[node] += sz[ne];
    }
    subtree[node] = binom(sz[node], k);
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      subtree[node] -= subtree[ne];
    }
  };
  dfs(0, -1);
  for (auto &x : subtree) cout << x << " ";
  cout << "\n";
  vector<Z> res(n);
  function<void(int, int, Z)> get_all = [&](int node, int fa, Z prev) {
    vector<tuple<Z, int, int>> sub;
    Z sum = 0;
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      sub.push_back({subtree[ne], sz[ne], ne});
      sum += subtree[ne];
    }
    sub.push_back({prev, n - sz[node], fa});
    for (auto &[sub_res, sub_sz, ne] : sub) {
      res[node] += binom(sz[node] - sub_sz, k) * (sz[node] - sub_sz + 1) - sum + sub_res;
    }
    for (auto &[sub_res, sub_sz, ne] : sub) {
      if (ne == fa) continue;
      get_all(ne, node, binom(sz[node] - sub_sz, k) - sum + sub_res);
    }
  };
  get_all(0, -1, 0);
  for (auto &x : res) cout << x << " ";
  cout << "\n";
  cout << accumulate(res.begin(), res.end(), Z(0)) << "\n";
}