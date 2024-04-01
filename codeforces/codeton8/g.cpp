#include <bits/stdc++.h>
using i64 = long long;

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
  int T;
  std::cin >> T;
  Comb comb(2e6);
  while (T--) {
    int a, b, c;
    std::cin >> a >> b >> c, a += 5;
    Z res = 0;

    Z total = comb.binom(a + c, a);
    Z remain_paths = total;
    for (int x = 5; x <= a; x++) {
      // #-1 = x, #1 = x - 5
      // last one is -1
      int neg_1 = x - 1, pos_1 = x - 5;
      // count: go neg_1 -1, pos_1 1, and prefix sum < 5
      // from 0 to -4
      // reflect: from -10 to -4

      Z cnt = comb.binom(pos_1 + neg_1, neg_1) - comb.binom(pos_1 + neg_1, x);
      // remain: #-1 = a - x, #1 = c - (x - 5)
      Z remain = comb.binom(a - x + c - (x - 5), a - x);
      Z p = cnt * remain / total * comb.binom(x, 5) / comb.binom(a, 5);
      res += p;
      remain_paths -= cnt * remain;
    }
    res += remain_paths / total;
    std::cout << res << "\n";
  }
}
