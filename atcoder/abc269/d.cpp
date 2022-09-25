#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y, st.insert({x, y});
  }
  int res = 0;
  set<pair<int, int>> seen;
  const vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
  function<void(int, int)> dfs = [&](int x, int y) {
    for (auto& [di, dj] : directions) {
      int xx = x + di, yy = y + dj;
      if (st.count({xx, yy}) && !seen.count({xx, yy})) {
        seen.insert({xx, yy});
        dfs(xx, yy);
      }
    }
  };
  for (auto& [x, y] : st) {
    if (seen.count({x, y})) continue;
    seen.insert({x, y});
    res++;
    dfs(x, y);
  }
  cout << res << "\n";
}
