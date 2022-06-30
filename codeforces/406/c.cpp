#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  int lc = 0, rc = 0, p = 0;
};

struct SegTree {
  vector<Node> t = {{}};  // init all
  SegTree() = default;
  SegTree(int n) { t.reserve(n * 20); }
  int modify(int p, int l, int r, int x, int v) {
    // p: original node, update a[x] -> v
    t.push_back(t[p]);
    int u = (int)t.size() - 1;
    if (r - l == 1) {
      t[u].p = v;
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
  int kth(int p, int l, int r, int k) {
    // last i s.t. query(0, i) <= k
    if (r - l == 1) return t[p].p <= k ? r : l;
    int mid = (l + r) / 2;
    if (t[t[p].lc].p > k) {
      return kth(t[p].lc, l, mid, k);
    } else {
      return kth(t[p].rc, mid, r, k - t[t[p].lc].p);
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x, x--;
  vector<int> ver(n), nex(n, -1);
  int p = 0;
  SegTree seg(n);
  for (int i = n - 1; i >= 0; i--) {
    if (nex[a[i]] != -1) p = seg.modify(p, 0, n, nex[a[i]], 0);
    p = seg.modify(p, 0, n, i, 1);
    nex[a[i]] = i;
    ver[i] = p;
  }
  for (int k = 1; k <= n; k++) {
    int res = 0;
    for (int i = 0; i < n;) {
      i = seg.kth(ver[i], 0, n, k);
      res++;
    }
    cout << res << " ";
  }
}
