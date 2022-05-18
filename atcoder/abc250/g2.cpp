#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Node {
  ll v = 1e18;
};
struct Tag {
  ll v = 0;
};
Node pull(const Node& a, const Node& b) { return {min(a.v, b.v)}; }

Tag pull(const Tag& a, const Tag& b) { return {a.v + b.v}; }

Node apply_tag(const Node& a, const Tag& b) { return {a.v + b.v}; }

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
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  SegTree seg(n);
  for (int i = 0; i < n; i++) seg.t[i + n] = {i + 1};
  for (int i = n - 1; i; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](ll x, ll y) { return a[x] > a[y]; });
  ll res = -accumulate(a.begin(), a.end(), 0ll);
  for (auto& i : order) {
    ll mini = seg.query(i, n).v;
    if (mini >= 2) {
      res += 2 * a[i];
      seg.modify(i, n, {-2});
    } else if (mini >= 1) {
      res += a[i];
      seg.modify(i, n, {-1});
    }
  }
  cout << res << "\n";
}
