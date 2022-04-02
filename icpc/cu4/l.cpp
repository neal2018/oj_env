#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  vector<array<int, 2>> points;
  int cnt = 0;
  for (auto& [x, y] : a) {
    points.push_back({x, 1});
    points.push_back({y + 1, -1});
  }
  for (int i = 0; i <= n; i++) {
    points.push_back({i, 0});
  }
  sort(points.begin(), points.end());
  int sz = int(points.size());
  int res = -1;
  for (int i = 0, j; i < sz; i = j) {
    for (j = i; points[j][0] == points[i][0];) j++;
    for (int k = i; k < j; k++) {
      auto [p, is_new] = points[k];
      // cout << "handle " << p << " " << is_new << endl;
      if (is_new == 1) {
        cnt++;
      } else if (is_new == -1) {
        cnt--;
      }
    }
    // cout << points[i][0] << " " << cnt << "\n";
    if (points[i][0] == cnt) {
      res = max(cnt, res);
    }
  }
  cout << res << "\n";
}