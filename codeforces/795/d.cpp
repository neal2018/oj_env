#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e14;

struct Node {
  ll v = -inf, sum = -inf, pre_sum = -inf, suf_sum = -inf;
};

Node pull(const Node &a, const Node &b) {
  return {max({a.v, b.v, a.suf_sum + b.pre_sum}), a.sum + b.sum, max(a.sum + b.pre_sum, a.pre_sum),
          max(b.sum + a.suf_sum, b.suf_sum)};
}

struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, const Node &v) {
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
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<ll> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](ll x, ll y) { return a[x] < a[y]; });
    SegTree seg(n);
    cout << ([&] {
      for (auto &i : order) {
        seg.modify(i, {a[i], a[i], a[i], a[i]});
        if (seg.query(0, n).v > a[i]) return false;
      }
      return true;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}