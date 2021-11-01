#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int MOD = 998244353;
ll norm(ll x) { return (x + MOD) % MOD; }
template <class T>
T power(T a, ll b) {
  T res = 1;
  for (; b; b /= 2, a *= a)
    if (b & 1) res *= a;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2); }
  Z &operator*=(const Z &rhs) { return x = x * rhs.x % MOD, *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const auto &_) { return *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const auto &_) { return lhs; }
  friend istream &operator>>(istream &input, Z &z) { return input >> z.x, input; }
};

Z f[100001], g[100001];

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  Z res = 0;
  for (int i = n - 2; i >= 0; i--) {
    f[a[i + 1]] += 1;
    for (int l = 1, r; l <= a[i + 1]; l = r + 1) {
      int v = a[i + 1] / l;
      r = a[i + 1] / v;
      int t = (a[i] + v - 1) / v;
      res += f[v] * (t - 1) * (i + 1);
      g[a[i] / t] += f[v];
      f[v] = 0;
    }
    for (int l = 1, r; l <= a[i]; l = r + 1) {
      int v = a[i] / l;
      r = a[i] / v;
      f[v] = g[v];
      g[v] = 0;
    }
  }
  for (int l = 1, r; l <= a[0]; l = r + 1) {
    int v = a[0] / l;
    r = a[0] / v;
    f[v] = 0;
  }

  cout << res.x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
