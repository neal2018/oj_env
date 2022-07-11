#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244853;
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
  auto operator<=>(const Z &) const = default;  // need c++ 20
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
  map<pair<int, int>, pair<int, int>> mp;
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w, u--, v--;
    if (u > v) swap(u, v);
    mp[{u, v}].first += w, mp[{u, v}].second++;
  }
  vector<int> a(k);
  for (auto &x : a) cin >> x, x--;
  Z res = 0;
  for (int i = 0; i < k - 1; i++) {
    int u = a[i], v = a[i + 1];
    if (u > v) swap(u, v);
    if (mp.count({u, v}) == 0) {
      cout << "Stupid Msacywy!\n";
      return 0;
    }
    res *= 10;
    Z temp = Z(mp[{u, v}].first) / mp[{u, v}].second;
    res += temp;
  }
  cout << res << "\n";
}
