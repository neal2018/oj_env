#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    if ((m + n - 1) & 1) {
      cout << "NO\n";
    } else {
      // (m+n-1)/2 1
      vector dp(n + 1, vector<bitset<2000>>(m + 1));
      if (a[0][0] == 1) {
        dp[1][1][1] = 1;
      } else {
        dp[1][1][0] = 1;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i != 0) {
            dp[i + 1][j + 1] |= dp[i][j + 1] << (a[i][j] == 1);
          }
          if (j != 0) {
            dp[i + 1][j + 1] |= dp[i + 1][j] << (a[i][j] == 1);
          }
        }
      }
      cout << (dp[n][m][(m + n - 1) / 2] ? "YES\n" : "NO\n");
    }
  }
}
