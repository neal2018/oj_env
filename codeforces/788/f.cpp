#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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

constexpr ll MAX_N = 1005, DIGIT = 60;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  vector<Z> f(MAX_N, 1), rf(MAX_N, 1);
  for (int i = 2; i < MAX_N; i++) f[i] = f[i - 1] * i % MOD;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i = MAX_N - 2; i > 1; i--) rf[i] = rf[i + 1] * (i + 1) % MOD;
  auto binom = [&](ll n, ll r) -> Z {
    if (n < 0 || r < 0 || n < r) return 0;
    return f[n] * rf[n - r] * rf[r];
  };
  ll n, l, r, z;
  cin >> n >> l >> r >> z;
  auto solve = [&](ll total) {
    map<array<ll, 2>, Z> memo;
    function<Z(ll, ll)> dfs = [&](ll cur, ll remain) {
      ll maxi = min(remain >> cur, 2 * n);
      if (memo.count({cur, maxi})) return memo[{cur, maxi}];
      Z res = 0;
      if (cur == -1) {
        res = 1;
      } else {
        for (int i = ((z >> cur) & 1); i <= min(n, maxi); i += 2) {
          res += dfs(cur - 1, remain - i * (1ll << cur)) * binom(n, i);
        }
      }
      return memo[{cur, maxi}] = res;
    };
    return dfs(DIGIT, total);
  };
  cout << solve(r) - solve(l - 1) << '\n';
}
