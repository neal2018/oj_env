#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr ll MAX_N = 6000;
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
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  string s;
  cin >> n >> k >> s;
  vector<ll> v{-1};
  vector<Z> f(MAX_N, 1), rf(MAX_N, 1);
  for (int i = 2; i < MAX_N; i++) f[i] = f[i - 1] * i % MOD;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i = MAX_N - 2; i > 1; i--) rf[i] = rf[i + 1] * (i + 1) % MOD;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') v.push_back(i);
  }
  v.push_back(n);

  Z res = 1;
  ll sz = v.size();
  for (int i = 1; i + k < sz && k != 0; i++) {
    // choose i, i+1, ..., i+k-1
    ll pre0 = v[i - 1] + 1, last0 = v[i + k] - 1;
    ll last02 = v[i + k - 1] - 1;
    res += f[last0 - pre0 + 1] * rf[k] * rf[last0 - pre0 + 1 - k];
    if (i > 1)
      res -= f[last02 - pre0 + 1] * rf[k - 1] * rf[last02 - pre0 + 1 - (k - 1)];
    else
      res -= 1;
  }
  cout << res << '\n';
}