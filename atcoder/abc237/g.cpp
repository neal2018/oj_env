#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  ll one = 0, total = 0, lazy = -1;
};

Node pull(const Node &a, const Node &b) { return {a.one + b.one, a.total + b.total}; }

struct SegTree {
  ll n, h = 0;
  vector<Node> t;
  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(n * 2) {}
  void apply(ll x, ll v) {
    if (v == 0) {
      t[x].one = 0;
    } else {
      t[x].one = t[x].total;
    }
    t[x].lazy = v;
  }
  void build(ll l) {
    for (l = (l + n) / 2; l > 0; l /= 2) {
      if (t[l].lazy == -1) {
        t[l] = pull(t[l * 2], t[l * 2 + 1]);
      }
    }
  }
  void push(ll l) {
    l += n;
    for (ll s = h; s > 0; s--) {
      ll i = l >> s;
      if (t[i].lazy != -1) {
        apply(2 * i, t[i].lazy);
        apply(2 * i + 1, t[i].lazy);
      }
      t[i].lazy = -1;
    }
  }
  void modify(ll l, ll r, int v) {
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
  int n, q, k;
  cin >> n >> q >> k;
  vector<SegTree> seg(2, SegTree(n));
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    seg[0].t[i + n] = {x >= k, 1};
    seg[1].t[i + n] = {x > k, 1};
  }
  for (int i = n - 1; i > 0; i--) {
    seg[0].t[i] = pull(seg[0].t[2 * i], seg[0].t[2 * i + 1]);
    seg[1].t[i] = pull(seg[1].t[2 * i], seg[1].t[2 * i + 1]);
  }
  while (q--) {
    int op, l, r;
    cin >> op >> l >> r, l--;
    if (op == 1) {
      for (auto &t : seg) {
        auto one = t.query(l, r).one;
        t.modify(l, r - one, 0);
        t.modify(r - one, r, 1);
      }
    } else {
      for (auto &t : seg) {
        auto one = t.query(l, r).one;
        t.modify(l, l + one, 1);
        if (l + one < n) t.modify(l + one, r, 0);
      }
    }
  }
  int res = -1;
  for (int i = 0; i < n; i++) {
    if (seg[0].query(i, i + 1).one != seg[1].query(i, i + 1).one) res = i;
  }
  cout << res + 1 << "\n";
}
