#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 1e9 + 1;
struct Node {
  int lc, rc, p;
};

struct SegTree {
  vector<Node> t = {{}};
  SegTree(int n) { t.reserve(n * 40); }
  int modify(int p, int l, int r, int x, int v) {
    if (p == 0) t.push_back(t[p]), p = (int)t.size() - 1;
    if (r - l == 1) {
      t[p].p += v;
    } else {
      int m = (l + r) / 2;
      if (x < m) {
        t[p].lc = modify(t[p].lc, l, m, x, v);
      } else {
        t[p].rc = modify(t[p].rc, m, r, x, v);
      }
      t[p].p = t[t[p].lc].p + t[t[p].rc].p;
    }
    return p;
  }
  int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return t[p].p;
    int m = (l + r) / 2, res = 0;
    if (x < m) res += query(t[p].lc, l, m, x, y);
    if (y > m) res += query(t[p].rc, m, r, x, y);
    return res;
  }
  int find(int p, int l, int r, ll x) {
    int m = (l + r) / 2;
    if (r - l == 1) {
      return l;
    } else {
      if (t[t[p].lc].p + m - 1 >= x) {
        return find(t[p].lc, l, m, x);
      } else {
        return find(t[p].rc, m, r, x - t[t[p].lc].p);
      }
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, p = 0, N = 1e9 + 1;
  cin >> n;
  SegTree seg(2e5);
  ll ans = 0, add = 0;
  auto find = [&](int x) { return seg.find(p, 0, N + 1, x - add); };
  for (int i = 0; i < n; i++) {
    cin >> t >> m;
    int p1 = find(t), p2 = find(t + 1);
    add++;
    p = seg.modify(p, 0, N + 1, p1, -1), p = seg.modify(p, 0, N + 1, p2, -1);
    for (ll j = 0, x; j < m; j++) {
      cin >> x;
      x = (x + ans) % MOD;
      cout << (ans = add + x + seg.query(p, 0, N + 1, 0, (int)x + 1)) << '\n';
    }
  }
}
