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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    int a[n], b[m];
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    sort(b, b + m);
    priority_queue<ll> pq;
    ll res = 0;
    for (auto& x : a) {
      ll l = lower_bound(b, b + m, x) - b;
      ll r = upper_bound(b, b + m, x) - b;
      pq.push(l), pq.push(r), pq.pop();
      res += l;
    }
    for (int i = 0; i < n; i++) {
      res -= pq.top(), pq.pop();
    }
    vector<int> d(a, a + n);
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    unordered_map<int, int> com;
    int sz = d.size();
    for (int i = 0; i < sz; i++) com[d[i]] = i;
    SegTree seg(sz);
    for (auto& x : a) {
      res += seg.query(com[x] + 1, sz);
      seg.modify(com[x], 1);
    }
    cout << res << '\n';
  }
}