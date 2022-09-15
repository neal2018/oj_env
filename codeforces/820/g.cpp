#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
template <typename T>
T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  static int norm(int x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
  }
  auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
  Z &operator*=(const Z &rhs) { return x = int(ll(x) * rhs.x % MOD), *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const int &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const int &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    int n = int(s.size()), m = int(t.size());
    vector<int> can;
    for (int i = 0; i + m <= n; i++) {
      if ([&] {
            for (int j = 0; j < m; j++) {
              if (s[i + j] != t[j]) return false;
            }
            return true;
          }())
        can.push_back(i);
    }
    int sz = int(can.size());
    if (sz == 0) {
      cout << "0 1\n";
      continue;
    }
    vector<int> dp(sz, inf);
    vector<Z> cnt(sz);
    for (int i = 0; i < sz; i++) {
      if (can[0] <= can[i] && can[i] < can[0] + m) {
        dp[i] = 1, cnt[i] = 1;
      }
    }
    for (int i = 0; i < sz; i++) {
      auto tt = [&] {
        for (int j = i + 1; j < sz; j++) {
          if (can[j] >= can[i] + m) return j;
        }
        return -1;
      }();
      if (tt != -1) {
        for (int j = i + 1; j < sz; j++) {
          if (can[tt] <= can[j] && can[j] < can[tt] + m) {
            if (dp[j] > dp[i] + 1) {
              dp[j] = dp[i] + 1, cnt[j] = cnt[i];
            } else if (dp[j] == dp[i] + 1) {
              cnt[j] += cnt[i];
            }
          }
        }
      }
    }
    int mini = inf;
    Z res = 0;
    for (int i = 0; i < sz; i++) {
      if (can[i] <= can.back() && can.back() < can[i] + m) {
        if (dp[i] < mini) {
          mini = dp[i], res = cnt[i];
        } else if (dp[i] == mini) {
          res += cnt[i];
        }
      }
    }
    cout << mini << " " << res << "\n";
  }
}
