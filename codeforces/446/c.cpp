#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 9;
template <typename T>
T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  constexpr Z(int _x = 0) : x(norm(_x)) {}
  constexpr static int norm(int x) {
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

constexpr Z A = 276601605, B = 691504013, C = 308495997;

struct Node {
  Z v = 0;
  int l = 0, r = 0;
};
struct Tag {
  Z v1 = 0, v2 = 0;
};
Node pull(const Node &a, const Node &b) { return {a.v + b.v, a.l, b.r}; }

Tag pull(const Tag &a, const Tag &b) { return {a.v1 + b.v1, a.v2 + b.v2}; }

Node apply_tag(const Node &a, const Tag &b) {
  return {a.v + A * B * b.v1 * (1 - power(B, a.r - a.l)) / (1 - B) -
              A * C * b.v2 * (1 - power(C, a.r - a.l)) / (1 - C),
          a.l, a.r};
}

struct SegTree {
  ll n, h;
  vector<Node> t;
  vector<Tag> lazy;
  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(2 * _n), lazy(2 * _n) {}
  void apply(ll x, const Tag &tag) {
    t[x] = apply_tag(t[x], tag);
    lazy[x] = pull(lazy[x], tag);
  }
  void build(ll l) {
    for (l = (l + n) / 2; l > 0; l /= 2) {
      if (lazy[l].v1 == 0 && lazy[l].v2 == 0) t[l] = pull(t[l * 2], t[2 * l + 1]);
    }
  }
  void push(ll l) {
    for (ll s = h; s > 0; s--) {
      ll i = (l + n) >> s;
      if (lazy[i].v1 != 0 || lazy[i].v2 != 0) {
        apply(2 * i, lazy[i]);
        apply(2 * i + 1, {lazy[i].v1 * power(B, t[2 * i].r - t[2 * i].l),
                          lazy[i].v2 * power(C, t[2 * i].r - t[2 * i].l)});
      }
      lazy[i] = Tag();
    }
  }
  void modify(ll l, ll r, const Tag &v) {
    push(l), push(r - 1);
    ll l0 = l, r0 = r;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l, {v.v1 * power(B, l0 - t[l].l), v.v2 * power(C, l0 - t[l].l)}), l++;
      if (r & 1) --r, apply(r, {v.v1 * power(B, l0 - t[r].l), v.v2 * power(C, l0 - t[r].l)});
    }
    build(l0), build(r0 - 1);
  }
  Node query(ll l, ll r) {
    push(l), push(r - 1);
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
  int n, q;
  cin >> n >> q;
  SegTree seg(n);
  for (int i = 0; i < n; i++) cin >> seg.t[i + n].v, seg.t[i + n].l = i, seg.t[i + n].r = i + 1;
  for (int i = n - 1; i; i--) seg.t[i] = pull(seg.t[2 * i], seg.t[2 * i + 1]);
  // auto print = [&] {
  //   for (int i = 0; i < n; i++) {
  //     auto node = seg.query(i, i + 1);
  //     cout << node.v << " ";
  //   }
  //   cout << "\n";
  // };
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r, l--;
    if (t == 1) {
      seg.modify(l, r, {1, 1});
    } else {
      auto node = seg.query(l, r);
      cout << node.v << "\n";
    }
    // print();
  }
}
