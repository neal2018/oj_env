#include <bits/stdc++.h>
using i64 = long long;

constexpr int MOD = 1e9 + 7;
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
  // \sum \sum i*(i-1)*..*(i-j+1) / j mod j
  // \sum \sum (j-1)! * [i/j] mod j
  // \sum_{i=1..n} \sum_{j = 4 or prime} (j-1)! * [i/j] mod j
  // \sum_{j = 4 or prime} \sum_{i=1..n} (j-1)! * [i/j] mod j
  constexpr int MAX_N = 1e6 + 10;
  auto comb = Comb(MAX_N);
  std::vector<Z> res(2 * MAX_N);

  std::vector<int> min_primes(MAX_N), primes;
  primes.reserve(MAX_N);
  for (int i = 2; i < MAX_N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto &p : primes) {
      if (p * i >= MAX_N) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }

  auto handle = [&](int j, int coef) {
    for (int i = j; i < MAX_N; i += j) {
      const auto add = coef * (i / j) % j;
      res[i] += add;
      res[i + j] -= add;
    }
  };

  for (auto j : primes) {
    handle(j, j - 1);
  }
  handle(4, 2);

  for ([[maybe_unused]] auto _ : std::views::iota(0, 2)) {
    for (int i = 1; i < MAX_N; i++) {
      res[i] += res[i - 1];
    }
  }
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::cout << res[n] << "\n";
  }
}
