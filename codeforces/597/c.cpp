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
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int n = int(s.size());
  if (count(s.begin(), s.end(), 'm') || count(s.begin(), s.end(), 'w')) {
    cout << "0\n";
    return 0;
  }
  vector<Z> dp(n, 1);
  for (int i = 1; i < n; i++) {
    if (i >= 2) {
      dp[i] = dp[i - 2] + dp[i - 1];
    } else {
      dp[i] = 1 + dp[i - 1];
    }
  }
  Z res = 1;
  for (int i = 0, j = 0; i < n; i = j) {
    for (j = i; j < n && s[i] == s[j];) j++;
    if ((s[i] == 'n' || s[i] == 'u') && (j - i >= 2)) {
      res *= dp[j - i - 1];
    }
  }
  cout << res << "\n";
}
