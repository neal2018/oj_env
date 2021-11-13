#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1e7 + 10;
int t[2 * MAX_N];
struct SegTree {
  int n;
  SegTree(int _n) : n(_n) {}
  void apply(int x, int v) { t[x] = max(t[x], v); }
  void modify(int l, int r, int v) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
  }
  int query(int p) {
    int res = t[p += n];
    for (p >>= 1; p > 0; p >>= 1) res = max(res, t[p]);
    return res;
  }
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, l, r;
  long long res = 0;
  char c;
  string s;
  cin >> n >> m >> s;
  SegTree seg(n);
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> c;
    seg.modify(l - 1, r, c);
  }
  for (int i = 0; i < n; i++) res += max(seg.query(i), (int)s[i]);
  cout << res << '\n';
}