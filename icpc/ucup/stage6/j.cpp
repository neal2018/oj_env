#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, ll v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  ll query(ll l, ll r) {
    assert(l <= r);
    ll res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k, m, q;
  cin >> n >> k >> m >> q, k--, m++;
  SegTree seg1(n), seg2(m);
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> b(m);
  for (auto& x : b) cin >> x;

  for (int i = 0; i < n; i++) seg1.t[n + i] = a[i];
  for (int i = n - 1; i >= 0; i--) seg1.t[i] = seg1.t[2 * i] + seg1.t[2 * i + 1];
  for (int i = 0; i < m; i++) seg2.t[m + i] = b[i];
  for (int i = m - 1; i >= 0; i--) seg2.t[i] = seg2.t[2 * i] + seg2.t[2 * i + 1];

  auto go0 = [&](int x) {
    if (x < k) {
      return seg1.query(0, x);
    } else if (x < n) {
      return seg1.query(x, n);
    } else {
      return seg2.query(0, x - n + 1);
    }
  };

  auto gok = [&](int x) {
    if (x < k) {
      return seg1.query(x, k);
    } else if (x < n) {
      return seg1.query(k, x);
    } else {
      return seg2.query(x - n + 1, m);
    }
  };

  auto go0k = [&] { return min({seg2.query(0, m), seg1.query(0, k), seg1.query(k, n)}); };

  auto is_left = [&](int x) { return 0 <= x && x < k; };
  auto is_right = [&](int x) { return k <= x && x < n; };
  auto is_center = [&](int x) { return n <= x && x < n + m; };

  while (q--) {
    char c;
    cin >> c;
    if (c == 'c') {
      int x;
      cin >> x, x--;
      if (seg1.t[n + x] >= inf) {
        seg1.modify(x, a[x]);
      } else {
        seg1.modify(x, inf);
      }
    } else if (c == 'x') {
      int x;
      cin >> x;
      if (seg2.t[m + x] >= inf) {
        seg2.modify(x, b[x]);
      } else {
        seg2.modify(x, inf);
      }
    } else {
      int x, y;
      cin >> x >> y, x--, y--;
      if (x > y) swap(x, y);
      ll res = inf;
      if (is_left(x) && is_left(y)) {
        res = min(res, seg1.query(x, y));
      }
      if (is_right(x) && is_right(y)) {
        res = min(res, seg1.query(x, y));
      }
      if (is_center(x) && is_center(y)) {
        res = min(res, seg2.query(x - n + 1, y - n + 1));
      }
      res = min(res, go0(x) + go0(y));
      res = min(res, gok(x) + gok(y));
      res = min(res, go0(x) + go0k() + gok(y));
      res = min(res, gok(x) + go0k() + go0(y));
      if (res >= inf) {
        cout << "impossible\n";
      } else {
        cout << res << "\n";
      }
    }
  }
}
