#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n), maxi, mini;
  for (auto &x : a) cin >> x;
  vector<Z> dp(n + 1), maxi_v, mini_v;
  Z maxi_sum = 0, mini_sum = 0;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    {
      Z sum_v = dp[i];
      while (maxi.size() && maxi.back() < a[i]) {
        maxi_sum -= maxi_v.back() * maxi.back();
        sum_v += maxi_v.back();
        maxi.pop_back(), maxi_v.pop_back();
      }
      maxi_sum += sum_v * a[i];
      maxi.push_back(a[i]), maxi_v.push_back(sum_v);
    }
    {
      Z sum_v = dp[i];
      while (mini.size() && mini.back() > a[i]) {
        mini_sum -= mini_v.back() * mini.back();
        sum_v += mini_v.back();
        mini.pop_back(), mini_v.pop_back();
      }
      mini_sum += sum_v * a[i];
      mini.push_back(a[i]), mini_v.push_back(sum_v);
    }
    dp[i + 1] = maxi_sum - mini_sum;
  }
  cout << dp[n] << '\n';
}