#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

constexpr int MOD = 998244353;
int power(int, i64) = delete;
template <typename T>
T power(T a, i64 b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  Z(long long _x) : x(norm(int((_x % MOD + MOD) % MOD))) {}
  static int norm(int x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
  }
  auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
  Z &operator*=(const Z &rhs) { return x = int(i64(x) * rhs.x % MOD), *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const int &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const int &rhs) { return lhs %= rhs; }
  friend auto &operator>>(std::istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(std::ostream &o, const Z &z) { return o << z.x; }
};

struct Comb {
  std::vector<Z> f, rf;
  Comb(int n = 2) : f(n, 1), rf(n, 1) { fill(2, n); }
  void fill(int start, int n) {
    f.resize(n), rf.resize(n);
    for (int i = start; i < n; i++) f[i] = f[i - 1] * i;
    rf[n - 1] = power(f[n - 1], MOD - 2);
    for (int i = n - 2; i >= start; i--) rf[i] = rf[i + 1] * (i + 1);
  }
  Z binom(int n, int r) {
    if (n < 0 || r < 0 || n < r) return 0;
    if (f.size() <= n) fill(int(f.size()), n + 1);
    return f[n] * rf[n - r] * rf[r];
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;

  std::sort(a.begin(), a.end());
  // if mean(remain) <= m: activate
  // else: not

  // res = \sum c_i
  // #remain = n - i
  // c_i = \sum( min(mean(remain), m) ) / \choose(n, #remain)
  // res = \sum_mask min(mean(mask), m) ) / \choose(n, #mask)
  auto comb = Comb(n * 2);
  constexpr int MAX = 210;
  std::vector<std::vector<Z>> dp(n + 1, std::vector<Z>(MAX * (n + 1)));
  // double res = 0;
  // for (int mask = 1; mask < 1 << n; mask++) {
  //   int sum = 0;
  //   int cnt = 0;
  //   for (int i = 0; i < n; i++) {
  //     if (mask >> i & 1) {
  //       sum += a[i];
  //       cnt++;
  //     }
  //   }
  //   res += min(sum, m * cnt) / double(cnt * comb.binom(n, cnt).x);
  // }
  dp[0][0] = 1;
  for (auto &x : a) {
    for (int cnt = n - 1; cnt >= 0; cnt--) {
      for (int prev = MAX * (n + 1) - x - 1; prev >= 0; prev--) {
        dp[cnt + 1][prev + x] += dp[cnt][prev];
      }
    }
  }
  Z res = 0;
  for (int cnt = 1; cnt <= n; cnt++) {
    auto coef = 1 / (cnt * comb.binom(n, cnt));
    for (int sum = 0; sum <= MAX * n; sum++) {
      res += min(sum, m * cnt) * coef * dp[cnt][sum];
    }
  }
  std::cout << res << '\n';
}
