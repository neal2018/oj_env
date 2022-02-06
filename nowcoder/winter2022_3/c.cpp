#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
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
  int m;
  cin >> m;
  vector<Z> dp(m + 1, 1);
  for (int i = 1; i <= m; i++) cin >> dp[i];
  vector<Z> cnt(2 * m + 4);
  for (int i = 1; i <= m; i++) {
    // for (int i = 0; i + x <= m; i++) {
    //   new_dp[i + x] += dp[i];
    // }
    // for (int i = 0; i + x / 2 <= m; i++) {
    //   new_dp[i + x / 2] += dp[i];
    // }
    cnt[2 * i] = dp[i];
    // cout << cnt[2 * i] << "\n";
    for (int _ = 0; _ < cnt[2 * i].x; _++) {
      for (int j = 0; j <= m; j++) {
        if (j - i >= 0) dp[j] -= dp[j - i];
        if (j - 2 * i >= 0) dp[j] -= dp[j - 2 * i];
      }
    }
  }
  Z n = accumulate(cnt.begin(), cnt.end(), Z(0));
  cout << n << "\n";
  for (int i = 2; i < 2 * m + 4; i += 2) {
    if (cnt[i].x > 0) {
      // cout << i << " " << cnt[i].x << "\n";
      for (int _ = 0; _ < cnt[i].x; _++) {
        cout << i << ' ';
      }
    }
  }
  cout << "\n";
}