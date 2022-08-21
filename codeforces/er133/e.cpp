#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// max subarray
struct Node {
  ll v = 0, sum = 0, pre_sum = 0, suf_sum = 0;
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
  int n;
  cin >> n;
  int N = 1 << n;
  vector<int> a(N);
  for (auto &x : a) cin >> x;
  SegTree seg(N);
  for (int i = 0; i < N; i++) seg.t[i + N] = {a[i], a[i], a[i], a[i]};
  for (int i = N - 1; i >= 0; i--) seg.t[i] = pull(seg.t[2 * i], seg.t[2 * i + 1]);
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
  }
}
