#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int q;
  cin >> q;
  vector<vector<pair<int, int>>> queries(n);
  vector<int> res(q);
  for (auto i : views::iota(0, q)) {
    int k, p;
    cin >> k >> p, k--, p--;
    queries[k].push_back({p, i});
  }
  SegTree seg(n);
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(),
       [&](int x, int y) { return a[x] != a[y] ? a[x] > a[y] : x < y; });
  for (int cur = 0; auto i : order) {
    seg.modify(i, 1);
    for (auto& [p, id] : queries[cur++]) {
      auto check = [&](ll mid) { return seg.query(0, mid) <= p; };
      ll l = 0, r = n - 1;
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid)) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      res[id] = a[l];
    }
  }
  for (auto& x : res) cout << x << "\n";
}
