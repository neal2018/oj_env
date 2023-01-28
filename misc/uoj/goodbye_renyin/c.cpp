#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e9;

struct Node {
  ll v = -inf;
};
struct Tag {
  ll v = -inf;
};
Node pull(const Node& a, const Node& b) { return {max(a.v, b.v)}; }

Tag pull(const Tag& a, const Tag& b) { return {max(a.v, b.v)}; }

Node apply_tag(const Node& a, const Tag& b) { return {max(a.v, b.v)}; }

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
      if (lazy[l].v == -inf) t[l] = pull(t[l * 2], t[2 * l + 1]);
    }
  }
  void push(ll l) {
    for (ll s = h; s > 0; s--) {
      ll i = (l + n) >> s;
      if (lazy[i].v != -inf) apply(2 * i, lazy[i]), apply(2 * i + 1, lazy[i]);
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
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<array<int, 6>> op(m);
  for (auto& [l, r, x, l2, r2, y] : op) {
    cin >> l >> r >> x >> l2 >> r2 >> y, l--, l2--;
  }
  while (q--) {
    int p, v;
    cin >> p >> v, p--;
    a[p] = v;
    SegTree seg(n);
    for (int i = 0; i < n; i++) seg.t[i + n].v = a[i];
    for (int i = n - 1; i > 0; i--) seg.t[i] = pull(seg.t[2 * i], seg.t[2 * i + 1]);
    for (auto& [l, r, x, l2, r2, y] : op) {
      auto node = seg.query(l, r);
      if (node.v >= x) {
        seg.modify(l2, r2, {y});
      }
    }
    auto node = seg.query(0, n);
    cout << node.v << "\n";
  }
}