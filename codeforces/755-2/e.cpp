#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
struct SegTree {
  int n;
  vector<int> t;
  SegTree(int _n) : n(_n) { t.resize(2 * n); }
  void modify(int p, int v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = t[p * 2] + t[p * 2 + 1];
  }
  int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};
struct SegTree2 {
  int n;
  vector<int> t;
  SegTree2(int _n) : n(_n) { t.resize(2 * n), fill(t.begin(), t.end(), n); }
  void modify(int p, int v) {
    p += n;
    t[p] = min(t[p], v);
    for (p /= 2; p; p /= 2) t[p] = min(t[p * 2], t[p * 2 + 1]);
  }
  int query(int l, int r) {
    int res = n;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) {
      pre[i + 1] = -pre[i] + a[i];
    }
    auto com = pre;
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    map<ll, ll> p;
    int sz = com.size();
    for (int i = 0; i < sz; i++) p[com[i]] = i;
    auto get = [&](ll x) { return upper_bound(com.begin(), com.end(), x) - com.begin(); };
    SegTree seg(sz);
    SegTree2 min_seg(sz);
    ll res = 0;
    for (int i = n - 1; i >= 0; i++) {
      ll min_neg = min_seg.query(0,p[pre[i]]);
      res+=seg.query(p[pre[i]], 0);
      seg.modify(p[pre[i + 1]], 1);
      min_seg.modify(p[pre[i + 1]], i);
    }
    cout << res << '\n';
  }
}