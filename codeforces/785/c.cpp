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
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  constexpr ll MAX = 4e4 + 10;
  vector<ll> p = {
      1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99,
  };
  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      p.push_back(i * 100 + j * 10 + i);
    }
  }
  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      p.push_back(i * 1000 + j * 100 + j * 10 + i);
    }
  }
  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        ll t = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
        if (t < MAX) p.push_back(t);
      }
    }
  }
  ll sz = p.size();
  // cout << sz << "\n";
  vector<vector<Z>> dp(MAX, vector<Z>(sz));  // dp sum to x with upto
  for (int j = 0; j < sz; j++) dp[0][j] = 1;
  for (int i = 1; i < MAX; i++) {
    for (int j = 0; j < sz; j++) {
      if (j > 0) dp[i][j] = dp[i][j - 1];
      if (i - p[j] >= 0) {
        dp[i][j] += dp[i - p[j]][j];
      }
    }
  }

  while (T--) {
    ll n;
    cin >> n;
    cout << dp[n].back() << "\n";
  }
}
