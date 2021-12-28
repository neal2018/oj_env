#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> g(n);
  for (auto& x : g) cin >> x;
  int dp[51][51][51][51];
  memset(dp, 0x3f, sizeof(dp));

  function<int(int, int, int, int)> dfs = [&](int x1, int y1, int x2, int y2) {
    if (x1 >= x2 || y1 >= y2) return 0;
    if (dp[x1][y1][x2][y2] < 1e9) {
      return dp[x1][y1][x2][y2];
    }
    int res = max(x2 - x1, y2 - y1);
    for (int i = x1; i < x2; i++) {
      int f = 1;
      for (int j = y1; j < y2; j++) {
        if (g[i][j] == '#') {
          f = 0;
          break;
        }
      }
      if (f) res = min(res, dfs(x1, y1, i, y2) + dfs(i + 1, y1, x2, y2));
    }
    for (int j = y1; j < y2; j++) {
      int f = 1;
      for (int i = x1; i < x2; i++) {
        if (g[i][j] == '#') {
          f = 0;
          break;
        }
      }
      if (f) res = min(res, dfs(x1, y1, x2, j) + dfs(x1, j + 1, x2, y2));
    }
    return dp[x1][y1][x2][y2] = res;
  };
  cout << dfs(0, 0, n, n) << "\n";
}