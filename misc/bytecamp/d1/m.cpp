#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
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
  ll n, m, c;
  cin >> n >> m >> c;
  vector a(n, vector<int>(m));
  for (auto &r : a) {
    for (auto &x : r) cin >> x;
  }
  vector<int> row(n), col(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      row[i] = max(row[i], a[i][j]);
      col[j] = max(col[j], a[i][j]);
    }
  }
  auto maxi = *max_element(row.begin(), row.end());
  cout << ([&]() -> Z {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] != min(row[i], col[j])) {
          return 0;
        }
      }
    }
    int r_cnt = int(count(row.begin(), row.end(), maxi));
    int c_cnt = int(count(col.begin(), col.end(), maxi));
    return power(Z(c - maxi + 1), r_cnt) + power(Z(c - maxi + 1), c_cnt) - 1;
  }());
}
