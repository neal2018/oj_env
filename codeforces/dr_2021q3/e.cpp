#include <bits/stdc++.h>
using namespace std;

struct Node {
  int a[3] = {}, ab = 0, bc = 0, abc = 0;
};

struct SegTree {
  int n;
  vector<Node> t;
  SegTree(int _n) : n(_n) { t.resize(2 * n); }
  Node merge(Node& a, Node& b) {
    Node c;
    for (int i = 0; i < 3; i++) c.a[i] = a.a[i] + b.a[i];
    c.ab = min(a.ab + b.a[1], a.a[0] + b.ab);
    c.bc = min(a.bc + b.a[2], a.a[1] + b.bc);
    c.abc = min({a.a[0] + b.abc, a.abc + b.a[2], a.ab + b.bc});
    return c;
  }
  void modify(int p, char c) {
    Node v;
    v.a[c - 'a']++, t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = merge(t[2 * p], t[2 * p + 1]);
  }
  Node query(int l, int r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = merge(left, t[l++]);
      if (r & 1) right = merge(t[--r], right);
    }
    return merge(left, right);
  }
};

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  SegTree seg(n);
  for (int i = 0; i < n; i++) seg.modify(i, s[i]);
  char c;
  for (int x; q--;) {
    cin >> x >> c;
    seg.modify(--x, c);
    cout << seg.query(0, n).abc << '\n';
  }
}
