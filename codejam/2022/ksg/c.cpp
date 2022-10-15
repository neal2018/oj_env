#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n, inf) {}
  void modify(ll p, ll v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = min(t[2 * p], t[2 * p + 1]);
  }
  int query(ll l, ll r) {
    ll res = inf;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> pre(n + 1);
    SegTree seg(n);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + a[i];
      seg.t[n + i] = pre[i + 1];
    }

    for (int i = n - 1; i >= 0; i--) seg.t[i] = min(seg.t[2 * i], seg.t[2 * i + 1]);
    vector<ll> pre_pre(n + 2, pre[0]);
    for (int i = 1; i <= n; i++) pre_pre[i] = pre_pre[i - 1] + pre[i];
    pre_pre.back() = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      // max t, s.t. a[i]+..+a[t]>=0
      // max t, s.t. pre(t+1, i) >= 0
      ll l = i, r = n;
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (seg.query(i, mid) >= pre[i]) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      res += pre_pre[l] - pre_pre[i] - pre[i] * (l - i);
    }
    cout << res << "\n";
  }
}
