#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n) { t.resize(2 * n, LONG_LONG_MAX); }
  void modify(ll p, ll v) {
    p += n;
    t[p] = min(t[p], v);
    for (p /= 2; p; p /= 2) t[p] = min(t[2 * p], t[2 * p + 1]);
  }
  ll query(ll l, ll r) {
    ll res = LONG_LONG_MAX;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(t[--r], res);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<array<ll, 2>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  SegTree seg(n);
  vector<vector<array<ll, 2>>> update(n);
  vector<int> stk;
  for (int i = 0; i < n; i++) {
    while (stk.size() && a[stk.back()][1] > a[i][1]) {
      ll pre = stk.back();
      ll val = abs(a[i][0] - a[pre][0]) * (a[i][1] + a[pre][1]);
      update[pre].push_back({i, val});
      stk.pop_back();
    }
    if (stk.size()) {
      ll pre = stk.back();
      ll val = abs(a[i][0] - a[pre][0]) * (a[i][1] + a[pre][1]);
      update[pre].push_back({i, val});
    }
    stk.push_back(i);
  }
  vector<vector<array<ll, 2>>> query(n);
  vector<ll> res(q);
  for (int i = 0, l, r; i < q; i++) {
    cin >> l >> r, l--;
    query[l].push_back({r, i});
  }
  for (int i = n - 1; i >= 0; i--) {
    for (auto& [r, val] : update[i]) seg.modify(r, val);
    for (auto& [r, pos] : query[i]) res[pos] = seg.query(0, r);
  }
  for (auto& x : res) cout << x << "\n";
}
