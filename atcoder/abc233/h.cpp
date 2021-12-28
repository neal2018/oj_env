#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

constexpr int MAX = 2e5;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n;
  vector<pair<int, int>> points(n);
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    points[i] = {x - y + 1e5, x + y};
  }
  sort(points.begin(), points.end());
  cin >> q;
  vector<tuple<int, int, int>> qs(q);
  for (int i = 0, a, b, k; i < q; i++) {
    cin >> a >> b >> k;
    qs[i] = {a - b + 1e5, a + b, k};
  }
  vector<int> l(q, 0), r(q, MAX);
  auto clip = [&](int x) { return clamp(x, 0, MAX); };
  while (true) {
    vector<int> cnt(q);
    vector<tuple<int, int, int, int, int>> ask;
    for (int i = 0; i < q; i++) {
      if (l[i] < r[i]) {
        int mid = (l[i] + r[i]) / 2;
        auto [x, y, k] = qs[i];
        ask.push_back({clip(x - mid), -1, clip(y - mid), clip(y + mid), i});
        ask.push_back({clip(x + mid) + 1, 1, clip(y - mid), clip(y + mid), i});
      }
    }
    if (ask.size() == 0) break;
    sort(ask.begin(), ask.end());
    SegTree seg(MAX + 1);
    int j = 0;
    for (auto& [x, c, D, U, i] : ask) {
      while (j < n && points[j].first < x) seg.modify(points[j++].second, 1);
      cnt[i] += c * seg.query(D, U + 1);
    }
    for (int i = 0; i < q; i++) {
      auto [x, y, k] = qs[i];
      if (l[i] < r[i]) {
        int mid = (l[i] + r[i]) / 2;
        if (cnt[i] >= k) {
          r[i] = mid;
        } else {
          l[i] = mid + 1;
        }
      }
    }
  }
  for (auto x : l) cout << x << " ";
  cout << "\n";
}