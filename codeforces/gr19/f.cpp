#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

ll MOD = 998244353;

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
  int n, q, xx;
  cin >> n >> q >> MOD;
  // (x^l - x^r*fib[r-l] - x^(r+1)*fib[r-l-1])/(1-x-x^2)
  // l              r
  // 1, 1, 2, 3, 5, 8, 13, 21
  //                1,  1,  2, 3, 5, 8, 11, 19 * 8
  //                    1,  1, 2, 3, 5,  8, 11 * 5
  vector<Z> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : a) cin >> xx, x -= xx;
  for (int i = n - 1; i >= 0; i--) {
    if (i > 0) a[i] -= a[i - 1];
    if (i > 1) a[i] -= a[i - 2];
  }
  int diff = 0;
  for (int i = 0; i < n; i++) diff += (a[i] != 0);
  vector<Z> fib(n + 1, 1);
  for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];
  auto add = [&](int i, Z v) {
    diff -= (a[i] != 0);
    a[i] += v;
    diff += (a[i] != 0);
  };
  while (q--) {
    char op;
    int l, r;
    cin >> op >> l >> r, l--;
    int p = (op == 'A' ? 1 : -1);
    add(l, p);
    if (r < n) add(r, -p * fib[r - l]);
    if (r + 1 < n) add(r + 1, -p * fib[r - l - 1]);
    cout << (diff ? "NO\n" : "YES\n");
  }
}
