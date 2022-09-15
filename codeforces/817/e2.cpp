#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long

struct DynamicSegTree {
  struct Node {
    int lc = 0, rc = 0, p = 0;
  };
  vector<Node> t = {{}, {}};  // init all
  DynamicSegTree() = default;
  DynamicSegTree(int n) { t.reserve(n * 20); }
  int modify(int p, int l, int r, int x, int v) {
    // p: original node, update a[x] -> a[x] + v
    int u = p;
    if (p == 0) t.push_back(t[p]), u = (int)t.size() - 1;
    if (r - l == 1) {
      t[u].p += v;
    } else {
      int mid = (l + r) / 2;
      if (x < mid) {
        t[u].lc = modify(t[p].lc, l, mid, x, v);
        t[u].rc = t[p].rc;
      } else {
        t[u].lc = t[p].lc;
        t[u].rc = modify(t[p].rc, mid, r, x, v);
      }
      t[u].p = t[t[u].lc].p + t[t[u].rc].p;
    }
    return u;
  }
  int query(int p, int l, int r, int x, int y) {
    // query sum a[x]...a[y-1] rooted at p
    // t[p] holds the info of [l, r)
    if (x <= l && r <= y) return t[p].p;
    int mid = (l + r) / 2, res = 0;
    if (x < mid) res += query(t[p].lc, l, mid, x, y);
    if (y > mid) res += query(t[p].rc, mid, r, x, y);
    return res;
  }
};

struct Fenwick {
  int n;
  vector<DynamicSegTree> a;
  Fenwick(int _n) : n(_n), a(n) {}
  void add(int x, int y, int inc = 1) {
    // add inc # of (x, y)
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1].modify(1, 0, n, y, inc);
    }
  }
  int sum(int x, int y) {
    int res = 0;  // # in [0, 0] to (x, y)
    for (int i = x; i > 0; i -= i & -i) {
      res += a[i - 1].query(1, 0, n, 0, y);
    }
    return res;
  }
  int range_sum(int x1, int x2, int y) { return sum(x2, y) - sum(x1, y); }
  int range_sum(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) + sum(x1, y1) - sum(x2, y1) - sum(x1, y2);
  }
};
#undef int

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    Fenwick tree(1001);
    for (ll i = 0, h, w; i < n; i++) {
      cin >> h >> w;
      tree.add(h, w, h * w);
    }
    while (q--) {
      ll hs, ws, hb, wb;
      cin >> hs >> ws >> hb >> wb;
      ll res = tree.range_sum(hs + 1, ws + 1, hb, wb);
      cout << res << "\n";
    }
  }
}
