#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

struct Node {
  ll v = 0;
};

Node pull(const Node& a, const Node& b) { return {max(a.v, b.v)}; }

struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n){};
  void modify(ll p, const Node& v) {
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
  cout << fixed << setprecision(20);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m), bad(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x, x--, bad[x] = 1;
  for (int i = 0; i < n; i++) a[i] -= i;
  ll pre = -1e18, f = 1, cnt = 0;
  for (int i = -1, j; i < n && f; i = j) {
    for (j = i + 1; j < n && bad[j] == 0;) j++;
    vector<ll> compress;
    compress.reserve(j - i + 1);
    for (int k = i + 1; k < j; k++) {
      compress.push_back(a[k]);
    }
    if (j != n) compress.push_back(a[j]);
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    ll sz = compress.size();
    SegTree seg(sz);
    for (int k = i + 1; k < j; k++) {
      if (a[k] < pre) continue;
      ll x = lower_bound(compress.begin(), compress.end(), a[k]) - compress.begin();
      ll maxi = seg.query(0, x + 1).v;
      seg.modify(x, {maxi + 1});
    }
    if (j != n) {
      ll x = lower_bound(compress.begin(), compress.end(), a[j]) - compress.begin();
      cnt += seg.query(0, x + 1).v;
    } else {
      cnt += seg.query(0, sz).v;
    }
    if (j != n) f &= (a[j] >= pre), pre = a[j];
  }
  cout << (f ? n - cnt - m : -1) << "\n";
}
