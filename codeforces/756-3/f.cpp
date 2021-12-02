#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
struct SegTree {
  int n;
  ll init;
  vector<int> t;
  SegTree(int _n, ll init) : n(_n), init(init) { t.resize(2 * n), fill(t.begin(), t.end(), init); }
  void modify(int p, int v) {
    p += n;
    t[p] = min(t[p], v);
    for (p /= 2; p; p /= 2) t[p] = min(t[p * 2], t[p * 2 + 1]);
  }
  int query(int l, int r) {
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
  ll T, n, s;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    vector<ll> a(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    set<pair<ll, ll>> st;
    vector d = vector(pre.begin() + 1, pre.end());
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    unordered_map<ll, ll> com;
    int sz = (int)d.size();
    for (int i = 0; i < sz; i++) com[d[i]] = i;
    SegTree seg(sz, n);
    auto get = [&](ll x) { return lower_bound(d.begin(), d.end(), x) - d.begin(); };
    ll maxi = 0, need = 0, start = -1;
    for (ll i = n - 1; i >= 0; i--) {
      seg.modify(com[pre[i + 1]], i);
      need = get(-s + pre[i]);
      ll last = seg.query(0, need);
      if (maxi < last - i) maxi = last - i, start = i;
    }
    if (start == -1)
      cout << start << '\n';
    else
      cout << start + 1 << ' ' << start + maxi << '\n';
  }
}