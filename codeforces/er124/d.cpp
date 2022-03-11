#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MAX = 1e6 + 1;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  set<pair<ll, ll>> all, seen;
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    a[i] = {x, y};
    all.insert(a[i]);
  }
  vector<pair<ll, ll>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<pair<ll, ll>> q, nq;
  map<pair<ll, ll>, pair<ll, ll>> source;
  for (auto& [x, y] : a) {
    for (auto& [dx, dy] : directions) {
      ll xx = x + dx, yy = y + dy;
      if (all.count({xx, yy}) == 0 && seen.count({xx, yy}) == 0) {
        seen.insert({xx, yy});
        q.push_back({xx, yy});
        source[{xx, yy}] = {xx, yy};
        break;
      }
    }
  }
  ll done = 0;
  for (; done < n; swap(q, nq), nq.clear()) {
    for (auto& [x, y] : q) {
      for (auto& [dx, dy] : directions) {
        ll xx = x + dx, yy = y + dy;
        if (all.count({xx, yy})) {
          source[{xx, yy}] = source[{x, y}];
          nq.push_back({xx, yy});
          all.erase({xx, yy});
          done++;
        }
      }
      if (done == n) break;
    }
  }
  for (auto& p : a) {
    cout << source[p].first << " " << source[p].second << "\n";
  }
}
