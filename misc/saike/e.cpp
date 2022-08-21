#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, ll v) {
    p += n;
    t[p] = max(t[p], v);
    for (p /= 2; p; p /= 2) t[p] = max(t[2 * p], t[2 * p + 1]);
  }
  ll query(ll l, ll r) {
    ll res = 0;
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
  vector<ll> b(n), dp(n);
  for (auto& x : b) cin >> x;
  vector<vector<pair<ll, ll>>> event(n);
  SegTree seg(n);
  for (int i = 0; i < n; i++) {
    for (auto& [p, v] : event[i]) seg.modify(p, v);
    ll l = i - a[i], r = i + a[i];
    ll add = 0;
    if (l >= 0) add = seg.query(0, l + 1);
    dp[i] = add + a[i] * b[i];
    if (r < n) event[r].push_back({i, dp[i]});
  }
  ll maxi = 0;
  for (auto& x : dp) maxi = max(maxi, x);
  cout << maxi << "\n";
}
