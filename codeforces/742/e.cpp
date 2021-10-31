#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
  ll total, l, r, start, end;  // index, inclusive
};
struct SegTree {
  ll n;
  vector<Node> t;
  vector<ll> a;
  SegTree(ll n) : n(n), t(2 * n), a(n){};
  Node pushup(Node& x, Node& y) {
    if (x.total == -1) return y;
    if (y.total == -1) return x;
    Node res = {x.total + y.total, x.l, y.r, x.start, y.end};
    if (a[x.r] <= a[y.l]) {
      res.total += x.end * y.start;
      if (x.start == x.r - x.l + 1) res.start = x.start + y.start;
      if (y.end == y.r - y.l + 1) res.end = x.end + y.end;
    }
    return res;
  }
  void modify(ll p, ll v) {
    a[p] = v;
    for (p = (p + n) / 2; p > 0; p /= 2) {
      t[p] = pushup(t[p * 2], t[p * 2 + 1]);
    }
  }
  Node query(ll l, ll r) { // [l,r)
    Node lres = {-1}, rres = {-1};
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) lres = pushup(lres, t[l++]);
      if (r & 1) rres = pushup(t[--r], rres);
    }
    return pushup(lres, rres);
  }
};

int main() {
  ll n, q, k, x, y;
  cin >> n >> q;
  SegTree seg(n);
  for (ll i = 0; i < n; i++) {
    cin >> seg.a[i];
    seg.t[i + n] = {1, i, i, 1, 1};
  }
  for (ll i = n - 1; i > 0; i--) {
    seg.t[i] = seg.pushup(seg.t[i * 2], seg.t[i * 2 + 1]);
  }
  while (q--) {
    cin >> k >> x >> y;
    if (k == 1) {
      seg.modify(x - 1, y);
    } else {
      cout << seg.query(x - 1, y).total << endl;
    }
  }
}