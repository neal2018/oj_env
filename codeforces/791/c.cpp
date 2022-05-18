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
  ll n, q;
  cin >> n >> q;
  SegTree seg_col(n), seg_row(n);
  vector<int> row(n), col(n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      ll x, y;
      cin >> x >> y, x--, y--;
      row[x]++, col[y]++;
      if (row[x] == 1) seg_row.modify(x, 1);
      if (col[y] == 1) seg_col.modify(y, 1);
    } else if (t == 2) {
      ll x, y;
      cin >> x >> y, x--, y--;
      row[x]--, col[y]--;
      if (row[x] == 0) seg_row.modify(x, -1);
      if (col[y] == 0) seg_col.modify(y, -1);
    } else {
      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2, x1--, y1--;
      if (seg_row.query(x1, x2) == x2 - x1 || seg_col.query(y1, y2) == y2 - y1) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
}
