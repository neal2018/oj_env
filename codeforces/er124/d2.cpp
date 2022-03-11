#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MAX = 1e6 + 1;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  while (T--) {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n), am(n);
    vector<pair<ll, ll>> xs(n), ys(n);
    set<pair<ll, ll>> all;
    for (int i = 0, x, y; i < n; i++) {
      cin >> x >> y;
      a[i] = {x, y};
      all.insert(a[i]);
      am[i] = {x - y, x + y};
      xs[i] = {x - y, i};
      ys[i] = {x + y, i};
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    auto get_dist = [&](const pair<ll, ll>& aa, const pair<ll, ll>& bb) {
      return max(abs(aa.first - bb.first), abs(aa.second - bb.second));
    };
    vector<pair<ll, ll>> res(n, {xs[0].first - 1, ys[0].first - 1});
    {
      ll pre = xs[0].first - 1;
      for (int i = 0; i < n; i++) {
        if (i == 0 || xs[i].first - 1 != xs[i - 1].first) {
          pre = xs[i].first - 1;
        }
        ll id = xs[i].second;
        if (get_dist(am[id], res[id]) > get_dist(am[id], {pre, am[id].second})) {
          if ((pre + am[id].second) & 1) {
            pair<ll,ll> pp = {(pre + 1 +  am[id].second) / 2, (am[id].second - (pre+1)) / 2};
            if (all.) {
            }
          } else {
            res[id] = {pre, am[id].second};
          }
        }
      }
    }
    {
      ll pre = xs[n - 1].first + 1;
      for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 || xs[i].first + 1 != xs[i + 1].first) {
          pre = xs[i].first + 1;
        }
        ll id = xs[i].second;
        if (get_dist(am[id], res[id]) > get_dist(am[id], {pre, am[id].second})) {
          res[id] = {pre, am[id].second};
        }
      }
    }
    {
      ll pre = ys[0].first - 1;
      for (int i = 0; i < n; i++) {
        if (i == 0 || ys[i].first - 1 != ys[i - 1].first) {
          pre = ys[i].first - 1;
        }
        ll id = ys[i].second;
        if (get_dist(am[id], res[id]) > get_dist(am[id], {am[id].first, pre})) {
          res[id] = {am[id].first, pre};
        }
      }
    }
    {
      ll pre = ys[n - 1].first + 1;
      for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 || ys[i].first + 1 != xs[i + 1].first) {
          pre = ys[i].first + 1;
        }
        ll id = ys[i].second;
        if (get_dist(am[id], res[id]) > get_dist(am[id], {am[id].first, pre})) {
          res[id] = {am[id].first, pre};
        }
      }
    }
    for (int i = 0; i < n; i++) {
      auto& [x, y] = res[i];
      if ((x + y) & 1) {
        if (x == am[i].first) {
          x--;
        } else {
          y--;
        }
      }
      pair<ll, ll> pp = {(x + y) / 2, (y - x) / 2};
      cout << pp.first << " " << pp.second << "\n";
    }
  }
}
