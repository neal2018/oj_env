#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, int v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  int query(ll l, ll r) {
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
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n), id(n);
    for (auto& x : p) cin >> x, x--;
    for (int i = 0; i < n; i++) id[p[i]] = i;
    SegTree seg(n);
    ll res = 0;
    for (int c = n - 1; c >= 0; c--) {
      for (int a = 0; a < c; a++) {
        if (p[a] < p[c]) {
          res += seg.query(a + 1, c);
        }
      }
      for (int pb = p[c] + 1; pb < n; pb++) {
        seg.modify(id[pb], 1);
      }
    }
    cout << res << "\n";
  }
}
