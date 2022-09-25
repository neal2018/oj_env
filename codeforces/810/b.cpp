#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  ll v = 0, l = 0, r = 0;
};
struct Tag {
  ll v = 0, d = 0, s = 0;
};
Node pull(const Node& a, const Node& b) { return {max(a.v, b.v), a.l, b.r}; }

Tag pull(const Tag& a, const Tag& b) {
  ll s = max(a.s, b.s);
  return {a.v + (s - a.s) * a.d + b.v + (s - b.s) * b.d, a.d + b.d, s};
}

Node apply_tag(const Node& a, const Tag& b) { return {max(a.v + b.v + (a.l - b.s) * b.d}; }

struct SegTree {
  ll n, h;
  map<ll, Node> t;
  map<ll, Tag> lazy;
  SegTree(ll _n) : n(_n), h((ll)log2(n)) {}
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
    if (l >= r) return;
    cout << "modify " << l << " " << r << " " << v.s << " " << v.v << " " << v.d << "\n";
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
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    SegTree seg(n);
    for (int i = 0; i < n; i++) seg.t[i + n] = {0, i, i + 1};
    for (int i = n - 1; i; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
    auto print = [&] {
      for (int i = 0; i < n; i++) {
        cout << seg.query(i, i + 1).v << " ";
      }
      cout << "\n";
    };
    vector<pair<int, int>> queries(m);
    for (auto& [x, p] : queries) {
      cin >> x >> p, x--;
      int left = max(0, x - p), lv = p - (x - left);
      seg.modify(left, min(n, x), {lv, 1, left});
      print();
      int right = min(n, x + p);
      seg.modify(x, right, {p, -1, x});
      print();
      cout << "\n";
    }
  }
}
