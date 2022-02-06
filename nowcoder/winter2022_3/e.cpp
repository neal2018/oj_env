#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;
constexpr ll MOD = 1e9 + 7;

ll norm(ll x) { return (x + MOD) % MOD; }
template <class T>
T power(T a, ll b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  // auto operator<=>(const Z &) const = default;
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, q;
  cin >> n >> m >> q;
  string s;
  cin >> s;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  auto output = [&](const string &t) {
    Z cur = 0;
    for (ll i = 0; i < n; i++) {
      cur = cur * 10 + (t[i] - '0');
    }
    cout << cur << "\n";
  };
  auto solve = [&]() {
    string t = s;
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && a[i] == a[j];) j++;
      sort(t.begin() + i, t.begin() + j, greater());
    }
    output(t);
  };
  solve();
  while (q--) {
    int p, qq;
    cin >> p >> qq;
    for (auto &x : a) {
      if (x == p) x = qq;
    }
    solve();
  }
}
