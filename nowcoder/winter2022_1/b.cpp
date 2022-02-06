#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
struct Node {
  int lc, rc;
  ll p[3] = {0, 0, 0};
};

struct SegTree {
  vector<Node> t = {{}};
  SegTree(int n) { t.reserve(n * 40); }
  int modify(int p, int l, int r, int x, ll v, int mod) {
    int u = p;
    if (p == 0) {
      t.push_back(t[p]);
      u = (int)t.size() - 1;
    }
    if (r - l == 1) {
      t[u].p[mod] = v;
    } else {
      int m = (l + r) / 2;
      if (x < m) {
        t[u].lc = modify(t[p].lc, l, m, x, v, mod);
      } else {
        t[u].rc = modify(t[p].rc, m, r, x, v, mod);
      }
      for (int i = 0; i < 3; i++) {
        ll rhs = (i + t[t[u].lc].p[i] + 3) % 3;
        t[u].p[i] = t[t[u].lc].p[i] + t[t[u].rc].p[rhs];
      }
    }
    return u;
  }
  ll query(int p, int l, int r, ll x, ll y, ll mod) {
    if (x <= l && r <= y) return t[p].p[mod];
    int m = (l + r) / 2;
    ll res = 0;
    if (x < m) res += query(t[p].lc, l, m, x, y, mod);
    if (y > m) res += query(t[p].rc, m, r, x, y, (res + mod + 3) % 3);
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  SegTree seg(n);
  int p = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int v = 0;
      if (s[i] == 'W') v = 1;
      if (s[i] == 'L' && j != 0) v = -1;
      p = seg.modify(p, 0, n, i, v, j);
    }
  }
  while (q--) {
    ll l, r, c;
    cin >> l >> r >> c;
    l--;
    ll res = seg.query(p, 0, n, l, r, (c + 3) % 3);
    // cout<<p<<endl;
    cout << res + c << '\n';
  }
}