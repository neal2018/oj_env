#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m, maxi = 0;
  string s, t;
  cin >> n >> m >> s >> t;
  if (n > m) swap(n, m), swap(s, t);
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]) - 1;
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
      }
      maxi = max(maxi, dp[i + 1][j + 1]);
    }
  }
  cout << maxi << "\n";
}
