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

vector<vector<Z>> pow_tmp(11, vector<Z>());

struct Node {
  ll maxi = 0, len = 0;
  array<Z, 11> a = {};
};

Node pull(const Node &a, const Node &b) {
  Node c;
  c.maxi = max(a.maxi, b.maxi), c.len = a.len + b.len;
  for (int i = 2; i <= 10; i++) {
    c.a[i] = a.a[i] * pow_tmp[i][b.len] + b.a[i];
  }
  return c;
}

struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n){};
  void modify(ll p, const Node& v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  Node query(ll l, ll r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  string s;
  cin >> n >> q >> s;
  for (int i = 2; i <= 10; i++) {
    pow_tmp[i].resize(n + 1, 1);
    for (int j = 1; j <= n; j++) pow_tmp[i][j] = pow_tmp[i][j - 1] * i;
  }
  auto get_val = [&](int x) -> array<Z, 11> {
    array<Z, 11> a = {};
    for (int i = 2; i <= 10; i++) {
      if (i > x) {
        a[i] = x;
      }
    }
    return a;
  };
  SegTree seg(n);
  for (int i = 0; i < n; i++) {
    seg.modify(i, {s[i] - '0', 1, get_val(s[i] - '0')});
  }
  while (q--) {
    int op, x, y;
    cin >> op >> x >> y, x--;
    if (op == 1) {
      seg.modify(x, {y, 1, get_val(y)});
    } else {
      auto node = seg.query(x, y);
      int maxi = max(2ll, node.maxi);
      cout << node.a[maxi + 1] << "\n";
    }
  }
}
