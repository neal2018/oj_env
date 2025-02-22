#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int MAX_N = 2e7;

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
  int T;
  std::cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    i64 g, w, l;
    std::cin >> w >> g >> l;
    auto d = w - g;

    std::cout << "Case #" << case_no << ": ";


    // E(l): go down when upper bound is L
    // E(0) = 1
    // E(l) = 1 + 1/2(E(l-1) + E(l))
    // E(l) = 2 + E(l-1)
    // E(l) = 1 + 2 * l
    std::cout << Z(d) * (1 + 2 * l) << "\n";
  }
}
