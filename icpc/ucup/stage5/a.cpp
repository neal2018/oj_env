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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  constexpr int MAX = 25;
  vector<int> sz(n, 1);
  vector<array<int, MAX>> and_val(n), or_val(n), xor_val(n);
  auto dfs = [&](auto &&self, int node, int fa) -> void {
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      self(self, ne, node);
      sz[node] += sz[ne];
      for (int i = 0; i < MAX; i++) {
        and_val[node][i] += and_val[ne][i];
        or_val[node][i] += or_val[ne][i];
        xor_val[node][i] += xor_val[ne][i];
      }
    }
    for (int i = 0; i < MAX; i++) {
      if (a[node] & (1 << i)) {
        or_val[node][i] = sz[node];
        xor_val[node][i] = sz[node] - xor_val[node][i];
      } else {
        and_val[node][i] = 0;
      }
    }
  };
  dfs(dfs, 0, -1);
  Z and_res = 0, or_res = 0, xor_res = 0;
  auto collect = [&](auto &&self, int node, int fa, array<int, MAX> and_prev,
                     array<int, MAX> or_prev, array<int, MAX> xor_prev) -> void {
    array<int, MAX> and_cur = and_prev, or_cur = or_prev, xor_cur = xor_prev;
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      for (int i = 0; i < MAX; i++) {
        and_cur[i] += and_val[ne][i];
        or_cur[i] += or_val[ne][i];
        xor_cur[i] += xor_val[ne][i];
      }
    }
    for (int i = 0; i < MAX; i++) {
      if (a[node] & (1 << i)) {
        or_val[node][i] = n;
        xor_val[node][i] = n - xor_val[node][i];
      } else {
        and_val[node][i] = 0;
      }
      if (and_val[node][i]) and_res += 1 << i;
      if (or_val[node][i]) or_res += 1 << i;
      if (xor_val[node][i]) xor_res += 1 << i;
    }
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      for (int i = 0; i < MAX; i++) {
        if (a[node] & (1 << i)) {
          and_cur[i] -= and_val[ne][i];
          or_cur[i] -= sz[ne];
          xor_cur[i] -= sz[ne] - xor_val[ne][i];
        } else {
          or_cur[i] -= or_val[ne][i];
          xor_cur[i] -= xor_val[ne][i];
        }
      }
      self(self, ne, node, and_cur, or_cur, xor_cur);
      for (int i = 0; i < MAX; i++) {
        if (a[node] & (1 << i)) {
          and_cur[i] += and_val[ne][i];
          or_cur[i] += sz[ne];
          xor_cur[i] += sz[ne] - xor_val[ne][i];
        } else {
          or_cur[i] += or_val[ne][i];
          xor_cur[i] += xor_val[ne][i];
        }
      }
    }
  };
  collect(collect, 0, -1, {}, {}, {});
  cout << and_res << " " << or_res << " " << xor_res << "\n";
}
