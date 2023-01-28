#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector dp(n + 1, vector<long double>(m + 1));
  for (int j = 1; j <= m; j++) dp[1][j] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int give = 0; give <= j; give++) {
        dp[i][j] = max(dp[i][j], give * 1.0 / j + dp[i - 1][j - give]);
      }
    }
  }
  cout << fixed << setprecision(10);
  cout << dp[n][m] << "\n";
}