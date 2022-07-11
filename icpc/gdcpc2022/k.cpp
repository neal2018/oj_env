#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;
template <typename T>
T power(T a, ll b, ll _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  static ll norm(ll x) { return (x % MOD + MOD) % MOD; }
  // auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
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
  int n, m, k;
  cin >> n >> m >> k;
  auto get_fib = [&](ll b) {
    array<Z, 4> res = {1, 0, 0, 1};
    array<Z, 4> a = {0, 1, 1, 1};
    auto mul = [&](array<Z, 4> &x, array<Z, 4> &y) {
      return array<Z, 4>{x[0] * y[0] + x[1] * y[2], x[0] * y[1] + x[1] * y[3],
                         x[2] * y[0] + x[3] * y[2], x[2] * y[1] + x[3] * y[3]};
    };
    for (; b; b /= 2) {
      if (b & 1) res = mul(res, a);
      a = mul(a, a);
    }
    return res;
  };
  auto print = [&]([[maybe_unused]] auto v) {
    // for (auto &r : v) {
    //   for (auto &x : r) cout << x << ' ';
    //   cout << "\n";
    // }
    // cout << "\n";
  };
  vector<vector<Z>> a(2 * n, vector<Z>(2 * n));
  for (int x = 0, i, j, w; x < m; x++) {
    cin >> i >> j >> w, i--, j--;
    auto t = get_fib(w);
    a[2 * i][2 * j] += t[0], a[2 * i][2 * j + 1] += t[1];
    a[2 * i + 1][2 * j] += t[2], a[2 * i + 1][2 * j + 1] += t[3];
  }
  print(a);
  auto mul = [&](vector<vector<Z>> &x, vector<vector<Z>> &y) {
    vector<vector<Z>> t(2 * n, vector<Z>(2 * n));
    for (int i = 0; i < 2 * n; i++) {
      for (int j = 0; j < 2 * n; j++) {
        for (int kk = 0; kk < 2 * n; kk++) {
          t[i][j] += x[i][kk] * y[kk][j];
        }
      }
    }
    return t;
  };
  vector<vector<Z>> gg(2 * n, vector<Z>(2 * n));
  for (int i = 0; i < 2 * n; i++) gg[i][i] = 1;
  for (; k; k /= 2) {
    if (k & 1) gg = mul(gg, a);
    a = mul(a, a);
  }
  print(gg);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << gg[2 * i][2 * j + 1] << " \n"[j == n - 1];
    }
  }
}
