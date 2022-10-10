#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

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
  int n, m;
  cin >> n >> m;
  vector<int> lis;
  map<pair<vector<int>, int>, Z> memo;
  function<Z(int)> dfs = [&](int i) -> Z {
    if (memo.count({lis, i})) {
      return memo[{lis, i}];
    }
    Z res = 0;
    if (i == n) {
      if (lis.size() == 3) res = 1;
    } else {
      for (int ii = 0; ii < m; ii++) {
        auto maxi = lower_bound(lis.begin(), lis.end(), ii);
        if (maxi == lis.end()) {
          if (lis.size() < 3) {
            lis.push_back(ii);
            res += dfs(i + 1);
            lis.pop_back();
          }
        } else {
          auto p = maxi - lis.begin();
          auto old = lis[p];
          lis[p] = ii;
          res += dfs(i + 1);
          lis[p] = old;
        }
      }
    }
    return memo[{lis, i}] = res;
  };
  Z res = dfs(0);
  // cout << memo.size() << endl;
  cout << res << "\n";
}
