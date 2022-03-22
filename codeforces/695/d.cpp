#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k, q;
  cin >> n >> k >> q, k++;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<Z>> p(k, vector<Z>(n));
  p[0] = vector<Z>(n, 1);
  for (int i = 1; i < k; i++) {
    for (int j = 1; j < n - 1; j++) p[i][j] = p[i - 1][j - 1] + p[i - 1][j + 1];
    p[i][0] = p[i - 1][1];
    p[i][n - 1] = p[i - 1][n - 2];
  }
  vector<Z> sum(n);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      sum[j] += p[i][j] * p[k - 1 - i][j];
    }
  }
  Z res = 0;
  for (int i = 0; i < n; i++) res += sum[i] * a[i];
  while (q--) {
    ll i, x;
    cin >> i >> x, i--;
    res -= sum[i] * a[i];
    a[i] = x;
    res += sum[i] * a[i];
    cout << res << "\n";
  }
}
