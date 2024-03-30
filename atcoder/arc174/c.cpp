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

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int raw_n;
  std::cin >> raw_n;
  // A, B
  // E(A, i) = i / n * (1 + E(B, i)) + (n - i) / n * E(B, i + 1)
  // E(B, i) = i / n * E(A, i) + (n - i) / n * E(A, i + 1)

  // (n - i * i / n) * E(A, i) = i + i * (n - i) / n * E(A, i + 1) + (n - i) * E(B, i + 1)
  // (n - i * i / n) * E(B, i) = i * i / n + i * (n - i) / n * E(B, i + 1) + (n - i) * E(A, i + 1)

  std::vector<Z> a(raw_n + 1), b(raw_n + 1);

  const auto n = Z(raw_n);
  for (i64 i = raw_n - 1; i >= 0; i--) {
    a[i] = (i + i * (n - i) / n * a[i + 1] + (n - i) * b[i + 1]) / (n - i * i / n);
    b[i] = (i * i / n + i * (n - i) / n * b[i + 1] + (n - i) * a[i + 1]) / (n - i * i / n);
  }
  std::cout << a[0] << " " << b[0] << "\n";
}
