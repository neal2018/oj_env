#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// template <typename T>
// struct Fenwick {
//   const int n;
//   std::vector<T> a;
//   Fenwick(int n) : n(n), a(n) {}
//   void add(int x, T v) {
//     for (int i = x + 1; i <= n; i += i & -i) {
//       a[i - 1] += v;
//     }
//   }
//   T sum(int x) {
//     T ans = 0;
//     for (int i = x; i > 0; i -= i & -i) {
//       ans += a[i - 1];
//     }
//     return ans;
//   }
//   T rangeSum(int l, int r) { return sum(r) - sum(l); }
// };
constexpr int MOD = 1e9 + 7;

constexpr int norm(int x) {
  if (x < 0) x += MOD;
  if (x >= MOD) x -= MOD;
  return x;
}
template <class T>
constexpr T power(T a, int b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  int x;
  constexpr Z(int _x = 0) : x(norm(_x)) {}
  // constexpr auto operator<=>(const Z &) const = default; // cpp20 only
  constexpr Z operator-() const { return Z(norm(MOD - x)); }
  constexpr Z inv() const { return power(*this, MOD - 2); }
  constexpr Z &operator*=(const Z &rhs) { return x = ll(x) * rhs.x % MOD, *this; }
  constexpr Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  constexpr Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  constexpr Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  constexpr Z &operator%=(const ll &rhs) { return x %= rhs, *this; }
  constexpr friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  constexpr friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  constexpr friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  constexpr friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  constexpr friend Z operator%(Z lhs, const ll &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

struct SegTree {
  int n;
  vector<Z> t;
  SegTree(int _n) : n(_n), t(2 * n) {}
  void modify(int p, Z v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  Z query(int l, int r) {
    Z res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

namespace GenHelper {
int z1, z2, z3, z4, z5, u, res;
int get() {
  z5 = ((z1 << 6) ^ z1) >> 13;
  z1 = ((int)(z1 & 4294967) << 18) ^ z5;
  z5 = ((z2 << 2) ^ z2) >> 27;
  z2 = ((z2 & 4294968) << 2) ^ z5;
  z5 = ((z3 << 13) ^ z3) >> 21;
  z3 = ((z3 & 4294967) << 7) ^ z5;
  z5 = ((z4 << 3) ^ z4) >> 12;
  z4 = ((z4 & 4294967) << 13) ^ z5;
  return (z1 ^ z2 ^ z3 ^ z4);
}
int read(int m) {
  u = get();
  u >>= 1;
  if (m == 0)
    res = u;
  else
    res = (u / 2345 + 1000054321) % m;
  return res;
}
void srand(int x) {
  z1 = x;
  z2 = (~x) ^ (0x23333333);
  z3 = x ^ (0x12345798);
  z4 = (~x) + 51;
  u = 0;
}
}  // namespace GenHelper

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, seed;
  cin >> n >> seed;
  GenHelper::srand(seed);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) a[i] = GenHelper::read(0), b[i] = GenHelper::read(i + 1);
  SegTree seg(n);
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  stable_sort(order.begin(), order.end(), [&](int x, int y) { return a[x] < a[y]; });
  Z res = 0;
  for (int i : order) {
    Z cur = seg.query(i - b[i], i) + 1;
    seg.modify(i, cur);
    res += cur;
  }
  cout << res << "\n";
  return 0;
}