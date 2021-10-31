#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define int long long
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, x;
  cin >> T;
  while (T--) {
    cin >> n;
    int cnt = 0;
    priority_queue<pair<int, int>> q;
    vector<tuple<int, int, int>> res;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x != 0) q.push({x, i});
    }
    while (q.size() > 1) {
      auto [x1, i1] = q.top();
      q.pop();
      auto [x2, i2] = q.top();
      q.pop();
      cnt += 1;
      res.push_back({i1, i2, 0});
      if (x1 > 1) {
        q.push({x1 - 1, i1});
      }
      if (x2 > 1) {
        q.push({x2 - 1, i2});
      }
    }
    cout << cnt << '\n';
    for (auto& [xx, y, z] : res) {
      cout << xx << ' ' << y << '\n';
    }
  }
}