#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n, -inf) {}
  void modify(ll p, ll v) {
    p += n;
    t[p] = max(t[p], v);
    for (p /= 2; p; p /= 2) t[p] = max(t[2 * p], t[2 * p + 1]);
  }
  ll query(ll l, ll r) {
    ll res = -inf;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = max(res, t[l++]);
      if (r & 1) res = max(res, t[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> pre(n + 1);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
  auto compress = pre;
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  for (auto& x : pre) x = lower_bound(compress.begin(), compress.end(), x) - compress.begin();
  SegTree seg(pre.size());
  seg.modify(pre[0], 1);
  ll dp = 0;
  // dp[i] = max(dp[j] - j) + i
  for (int i = 0; i < n; i++) {
    ll node = seg.query(0, pre[i + 1] + 1);
    dp = max(dp, node + i);
    seg.modify(pre[i + 1], dp - i);
  }
  cout << dp << "\n";
}
