#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

struct SegTree {
  ll n;
  int init;
  vector<int> t;
  SegTree(ll _n, int _init) : n(_n), init(_init), t(2 * n, _init) {}
  void modify(ll p, int v) {
    p += n;
    t[p] = min(t[p], v);
    for (p /= 2; p; p /= 2) t[p] = min(t[2 * p], t[2 * p + 1]);
  }
  int query(ll l, ll r) {
    int res = init;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n), dp(n);
  ll maxi = 0;
  for (auto& x : a) cin >> x, maxi = max(maxi, x);
  ll res = 0;
  for (ll i = 0, pre = 0; i < n; i++) {
    ll cur = min(a[i], pre + 1);
    res += cur;
    pre = cur;
    dp[i] = cur;
  }
  vector<ll> pre(n + 1);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
  vector<ll> predp(n + 1);
  for (int i = 0; i < n; i++) predp[i + 1] = predp[i] + dp[i];
  int q;
  cin >> q;
  vector<vector<pair<ll, ll>>> queries(n);
  for (ll i = 0, p, x; i < q; i++) {
    cin >> p >> x, p--;
    queries[p].push_back({x, i});
  }
  vector<ll> output(q);
  maxi++;
  SegTree seg(maxi + n, n);
  auto cost = [&](int i, ll x) {
    x = min(i == 0 ? 1ll : dp[i - 1] + 1, x);
    // find min t, s.t.,  a[i+t] - (i+t) < x-i
    auto last = seg.query(0, x - i + n);
    auto origin = predp[last] - predp[i];
    auto o_last = seg.query(0, a[i] - i + n);
    if (o_last > last) {
      origin = (a[i] + a[i] + o_last - i - 1) * (o_last - i) / 2;
    }
    // x
    auto gain = (x + x + last - i - 1) * (last - i) / 2;
    if (o_last > last) {
      gain += predp[o_last] - predp[last];
    }
    return gain - origin;
  };
  for (int i = n - 1; i >= 0; i--) {
    for (auto& [x, id] : queries[i]) {
      auto cur = res + cost(i, x);
      auto calc = [&](auto&& a) {
        ll res = 0, pre = 0;
        for (int i = 0; i < n; i++) {
          ll cur = min(a[i], pre + 1);
          res += cur;
          pre = cur;
        }
        return res;
      };
      {
        auto t = a[i];
        a[i] = x;
        // assert(calc(a) == cur);
        // cout << calc(a) << "\n";
        a[i] = t;
      }
      output[id] = cur;
    }
    seg.modify(a[i] - i + n, i);
  }
  for (auto& x : output) {
    cout << x << "\n";
  }
}
