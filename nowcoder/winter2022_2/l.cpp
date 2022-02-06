#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

ll norm(ll x) { return (x + MOD) % MOD; }
template <class T>
T power(T a, ll b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  // auto operator<=>(const Z &) const = default;
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

struct Node {
  int lc, rc;
  Z p = 0;
};

struct SegTree {
  vector<Node> t = {{}};
  SegTree(int n) { t.reserve(n * 20); }
  int modify(int p, ll l, ll r, ll x, Z v) {
    // maintain the product of the range
    // p: original node, update a[x] -> a[x]*v
    t.push_back(t[p]);
    int u = (int)t.size() - 1;
    if (r - l == 1) {
      t[u].p += v;
    } else {
      ll m = (l + r) / 2;
      if (x < m) {
        t[u].lc = modify(t[p].lc, l, m, x, v);
      } else {
        t[u].rc = modify(t[p].rc, m, r, x, v);
      }
      t[u].p = t[t[u].lc].p + t[t[u].rc].p;
    }
    return u;
  }
  Z query(int p, ll l, ll r, ll x, ll y) {
    // query product a[x]...a[y-1] rooted at p
    // t[p] holds the info of [l, r)
    if (x <= l && r <= y) return t[p].p;
    ll m = (l + r) / 2;
    Z res = 0;
    if (x < m) res += query(t[p].lc, l, m, x, y);
    if (y > m) res += query(t[p].rc, m, r, x, y);
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
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    a[i] = GenHelper::read(0), b[i] = GenHelper::read(i + 1);
  }
  auto v = a;
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  int sz = (int)v.size();
  for (int i = 0; i < n; i++) {
    a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
  }
  vector<Z> dp(n);
  SegTree seg(sz);
  vector<int> ver(n + 1);
  int p = 0;
  for (int i = 0; i < n; i++) {
    ll left = max(0ll, i - b[i]);
    Z all = seg.query(p, 0, sz, 0, a[i] + 1);
    Z minus = seg.query(ver[left], 0, sz, 0, a[i] + 1);
    dp[i] = all - minus + 1;
    p = seg.modify(p, 0, sz, a[i], dp[i]);
    ver[i + 1] = p;
  }
  Z res = accumulate(dp.begin(), dp.end(), Z(0));
  cout << res << "\n";
  return 0;
}