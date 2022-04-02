#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr ll MOD = 1e9 + 9;

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
  int k, b;
  cin >> k >> b;
  map<pair<int, int>, pair<Z, Z>> memo;
  function<pair<Z, Z>(int, int)> dfs = [&](int cur, int remain) -> pair<Z, Z> {
    if (memo.count({cur, remain})) return memo[{cur, remain}];
    Z res = 0, cnt = 0;
    if (cur == b) {
      res = (remain == 0);
    } else {
      auto [res0, cnt0] = dfs(cur + 1, (remain * 2) % k);
      res += res0;
      auto [res1, cnt1] = dfs(cur + 1, (remain * 2 + 1) % k);
      res += res1;
      cnt += res1 + cnt1 + cnt0;
    }
    return memo[{cur, remain}] = {res, cnt};
  };
  auto [res, cnt] = dfs(0, 0);
  cout << cnt << "\n";
}