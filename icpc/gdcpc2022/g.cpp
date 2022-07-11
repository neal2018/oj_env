#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

struct Node {
  ll v = inf, lazy = -1;
};

Node pull(const Node &a, const Node &b) { return {min(a.v, b.v)}; }

struct SegTree {
  ll n, h = 0;
  vector<Node> t;
  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(n * 2) {}
  void apply(ll x, ll v) {
    t[x].v += v;
    if (t[x].lazy == -1) t[x].lazy = 0;
    t[x].lazy += v;
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
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  SegTree seg(n);
  int pre = 0;
  set<ll> left, right;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      pre++;
      left.insert(i);
    } else {
      pre--;
      right.insert(i);
    }
    seg.t[i + n] = {pre, -1};
  }
  for (int i = n - 1; i; i--) seg.t[i] = pull(seg.t[2 * i], seg.t[2 * i + 1]);
  while (q--) {
    ll p;
    cin >> p, p--;
    if (s[p] == '(') {
      s[p] = ')';
      left.erase(p);
      right.insert(p);
      seg.modify(p, n, -2);
      ll r = *right.begin();
      s[r] = '(';
      right.erase(r);
      left.insert(r);
      seg.modify(r, n, 2);
      cout << r + 1 << "\n";
    } else {
      s[p] = '(';
      right.erase(p);
      left.insert(p);
      seg.modify(p, n, 2);
      auto check = [&](ll mid) {
        auto it = left.lower_bound(mid);
        if (it == left.end()) return 0;
        mid = *it;
        seg.modify(mid, n, -2);
        int f = (seg.query(0, n).v >= 0);
        seg.modify(mid, n, 2);
        return f;
      };
      ll l = 0, r = n;
      while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      r = *left.lower_bound(r);
      s[r] = ')';
      left.erase(r);
      right.insert(r);
      seg.modify(r, n, -2);
      cout << r + 1 << "\n";
    }
  }
}
