#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
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
  Z v = 0;
};
struct SegTree {
  int n;
  vector<Node> t;
  SegTree(int _n) : n(_n) { t.resize(2 * n); }
  Node merge(const Node &a, const Node &b) { return {a.v + b.v}; }
  void modify(int p, Z v) {
    Node vv{v};
    t[p += n] = vv;
    for (p /= 2; p; p /= 2) t[p] = merge(t[2 * p], t[2 * p + 1]);
  }
  Node query(int l, int r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = merge(left, t[l++]);
      if (r & 1) right = merge(t[--r], right);
    }
    return merge(left, right);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<Z> a(n);
  for (auto &x : a) cin >> x;
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == '*') p[i] = p[i - 1];
  }
  SegTree seg(n);
  for (int i = 0, j; i < n; i = j) {
    j = i;
    while (j < n && p[i] == p[j]) j++;
    Z cur = 1;
    for (int k = i; k < j; k++) {
      cur *= a[k];
    }
    seg.modify(i, cur);
  }
  while (q--) {
    int x;
    Z y;
    cin >> x >> y, x--;
    int pp = p[x];
    Z pre = seg.query(pp, pp + 1).v;
    pre = pre / a[x] * y;
    a[x] = y;
    seg.modify(pp, pre);
    cout << seg.query(0, n).v << "\n";
  }
}
