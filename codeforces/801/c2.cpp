#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    if ((m + n - 1) & 1) {
      cout << "NO\n";
    } else {
      // (m+n-1)/2 1
      int mini = [&] {
        vector dp(n, vector<int>(m, inf));
        dp[0][0] = a[0][0];
        for (auto i : views::iota(0, n)) {
          for (auto j : views::iota(0, m)) {
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j]);
          }
        }
        return dp[n - 1][m - 1];
      }();
      int maxi = [&] {
        vector dp(n, vector<int>(m, -inf));
        dp[0][0] = a[0][0];
        for (auto i : views::iota(0, n)) {
          for (auto j : views::iota(0, m)) {
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
          }
        }
        return dp[n - 1][m - 1];
      }();
      cout << ((mini <= 0 && maxi >= 0) ? "YES\n" : "NO\n");
    }
  }
}
