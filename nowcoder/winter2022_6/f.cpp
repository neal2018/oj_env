#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
constexpr ll MOD = 998244353;

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
constexpr ll MAX_N = 1e5 + 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<Z> f(MAX_N, 1), rf(MAX_N, 1);
  for (int i = 2; i < MAX_N; i++) f[i] = f[i - 1] * i;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i = MAX_N - 2; i > 1; i--) rf[i] = rf[i + 1] * (i + 1);
  auto binom = [&](ll n, ll r) {
    if (n < 0 || r < 0 || n < r) return decltype(f)::value_type(0);
    return f[n] * rf[n - r] * rf[r];
  };
  int n, k;
  cin >> n >> k;
  vector<ll> x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) { return x[i] * y[j] > x[j] * y[i]; });
  vector<array<ll, 3>> a(k);
  for (auto &[xx, op, yy] : a) cin >> op >> xx >> yy, xx--, yy--;
  sort(a.begin(), a.end());
  ll left = 0, right = n - 1, pre = -1;
  Z ans = 1;
  for (auto &[xx, op, yy] : a) {
    ll step = 0;
    if (op == 1) {
      while (p[left + step] != yy) step++;
      left += step + 1;
      right -= (xx - pre) - (step + 1);
    } else {
      while (p[right - step] != yy) step++;
      left += (xx - pre) - (step + 1);
      right -= step + 1;
    }
    ans *= binom(xx - pre - 1, step);
    pre = xx;
  }
  ans *= power(Z(2), n - 1 - pre);
  cout << ans << '\n';
}
