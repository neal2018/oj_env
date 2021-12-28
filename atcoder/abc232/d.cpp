#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, res = 0;
  cin >> n >> m;
  vector<string> c(n);
  for (auto& x : c) cin >> x;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
  dp[0][1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '.') {
        dp[i + 1][j + 1] = 1 + max(dp[i][j + 1], dp[i + 1][j]);
      }
      res = max(res, dp[i + 1][j + 1]);
    }
  }
  cout << res << '\n';
}