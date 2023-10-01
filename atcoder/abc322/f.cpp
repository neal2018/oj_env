#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  ll init = 0, pre_1 = 0, suf_1 = 0, pre_0 = 0, suf_0 = 0, max_1 = 0, max_0 = 0, len = 0;
};

auto get_node(int x) {
  if (x == 0) {
    return Node{1, 0, 0, 1, 1, 0, 1, 1};
  } else {
    return Node{1, 1, 1, 0, 0, 1, 0, 1};
  }
}

struct Tag {
  ll v = 0;
};
Node pull(const Node& a, const Node& b) {
  if (a.init == 0) return b;
  if (b.init == 0) return a;
  return {1,
          a.pre_1 + (a.pre_1 == a.len) * b.pre_1,
          b.suf_1 + (b.suf_1 == b.len) * a.suf_1,
          a.pre_0 + (a.pre_0 == a.len) * b.pre_0,
          b.suf_0 + (b.suf_0 == b.len) * a.suf_0,
          max({a.max_1, b.max_1, a.suf_1 + b.pre_1}),
          max({a.max_0, b.max_0, a.suf_0 + b.pre_0}),
          a.len + b.len};
}

Tag pull(const Tag& a, const Tag& b) { return {a.v ^ b.v}; }

Node apply_tag(const Node& a, const Tag& b) {
  if (b.v == 0) return a;
  auto res = a;
  res.pre_1 = a.pre_0;
  res.pre_0 = a.pre_1;
  res.suf_1 = a.suf_0;
  res.suf_0 = a.suf_1;
  res.max_1 = a.max_0;
  res.max_0 = a.max_1;
  return res;
}

struct SegTree {
  ll n, h;
  vector<Node> t;
  vector<Tag> lazy;
  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(2 * _n), lazy(2 * _n) {}
  void apply(ll x, const Tag& tag) {
    t[x] = apply_tag(t[x], tag);
    lazy[x] = pull(lazy[x], tag);
  }
  void build(ll l) {
    for (l = (l + n) / 2; l > 0; l /= 2) {
      if (!lazy[l].v) t[l] = pull(t[l * 2], t[2 * l + 1]);
    }
  }
  void push(ll l) {
    for (ll s = h; s > 0; s--) {
      ll i = (l + n) >> s;
      if (lazy[i].v) apply(2 * i, lazy[i]), apply(2 * i + 1, lazy[i]);
      lazy[i] = Tag();
    }
  }
  void modify(ll l, ll r, const Tag& v) {
    push(l), push(r - 1);
    ll l0 = l, r0 = r;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
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
  string s;
  cin >> n >> q >> s;
  SegTree seg(n);
  for (int i = 0; i < n; i++) seg.t[i + n] = get_node(s[i] - '0');
  for (int i = n - 1; i >= 0; i--) seg.t[i] = pull(seg.t[2 * i], seg.t[2 * i + 1]);
  while (q--) {
    int c, l, r;
    cin >> c >> l >> r, l--;
    if (c == 1) {
      seg.modify(l, r, {1});
    } else {
      auto node = seg.query(l, r);
      cout << node.max_1 << "\n";
    }
  }
}
