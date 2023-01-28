#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n), t(2 * n, inf) {}
  void modify(ll p, int v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = min(t[2 * p], t[2 * p + 1]);
  }
  int query(ll l, ll r) {
    int res = inf;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; i++) {
    auto &[x, y] = a[i];
    x = i, cin >> y, y--;
  }
  vector<int> res(n, inf);
  for (int t = 4; t > 0; t--) {
    for (int tt = 2; tt > 0; tt--) {
      vector<int> order(n);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(), [&](int i, int j) {
        auto [xi, yi] = a[i];
        auto [xj, yj] = a[j];
        return xi > xj;
      });
      SegTree seg(2 * n);
      for (auto &i : order) {
        auto &[x, y] = a[i];
        auto node = seg.query(y - x + n, 2 * n);
        if (node != inf) res[i] = min(res[i], node - y - x);
        seg.modify(y - x + n, y + x);
        swap(x, y);
      }
    }
    for (auto &[x, y] : a) {
      int nx = y, ny = -x + n - 1;
      x = nx, y = ny;
    }
  }
  for (auto &x : res) cout << x << " ";
  cout << "\n";
}
