#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
int power(int, ll) = delete;
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

struct Comb {
  vector<Z> f, rf;
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
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  Comb comb(n);
  auto get = [&](const vector<int> &f, int val) {
    Z res = 0;
    for (int i = 0; i < n; i++) {
      res += (i % 2 ? -1 : 1) * comb.binom(n - 1, i) * f[val + i];
    }
    return res;
  };
  auto a0 = get(a, 0);
  auto a1 = get(a, 1);
  auto b0 = get(b, 0);

  cout << (b0 - a0) / (a1 - a0) << "\n";
}