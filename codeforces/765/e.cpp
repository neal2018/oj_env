#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

struct Node {
  ll v = 0, p = inf, cnt = 0;
};

Node merge(const Node& a, const Node& b) {
  return {a.v + b.v, min(a.p, b.p), (a.p < b.p) ? a.cnt : (a.p > b.p ? b.cnt : a.cnt + b.cnt)};
}

struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n){};
  void modify(ll p, Node v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = merge(t[p * 2], t[p * 2 + 1]);
  }
  Node query(ll l, ll r) {
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
  ll n, q;
  string s;
  cin >> n >> q >> s;
  vector<ll> p(n, -1), match(n, -1), stk, out(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push_back(i);
    } else if (stk.size()) {
      ll x = stk.back();
      stk.pop_back();
      match[i] = x, match[x] = i;
      if (x > 0) {
        p[x] = s[x - 1] == '(' ? x - 1 : (match[x - 1] >= 0 ? p[match[x - 1]] : -1);
      }
    }
  }
  for (auto& x : p)
    if (x != -1) out[x]++;
  SegTree seg(n);
  for (ll i = 0; i < n; i++)
    if (match[i] > i) seg.t[i + n] = {out[i] * (out[i] + 1) / 2, p[i], 1};
  for (ll i = n - 1; i > 0; i--) seg.t[i] = merge(seg.t[i * 2], seg.t[i * 2 + 1]);
  while (q--) {
    ll op, l, r;
    cin >> op >> l >> r, l--;
    if (op == 1) {
      seg.modify(l, {0, inf, 0});
      ll x = p[l];
      if (x != -1) out[x]--, seg.modify(x, {out[x] * (out[x] + 1) / 2, p[x], 1});
    } else {
      auto v = seg.query(l, r);
      cout << v.v + v.cnt * (v.cnt + 1) / 2 << "\n";
    }
  }
}
