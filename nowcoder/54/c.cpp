#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
struct SegTree {
  int n;
  vector<int> t;
  SegTree(int _n) : n(_n) { t.resize(2 * n); }
  int query(int l, int r) {
    int res = 1e9;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, b;
  cin >> n;
  SegTree seg(n);
  for (int i = 0; i < n; i++) {
    cin >> seg.t[i + n];
  }
  for (int i = n - 1; i >= 0; i--) seg.t[i] = min(seg.t[2 * i], seg.t[2 * i + 1]);
  cin >> b;
  string s;
  cin >> s;
  ll res = 1e18;
  for (int k = 0; k <= n; k++) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') continue;
      cnt += seg.query(max(0, i - k), i + 1);
    }
    cnt += k * b;
    // cout << k << " " << cnt << '\n';
    res = min(res, cnt);
  }
  cout << res << '\n';
}