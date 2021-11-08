#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    vector<vector<int>> left(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      int rolling = 0;
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '*') {
          left[i][j] = ++rolling;
        } else {
          rolling = 0;
        }
      }
    }
    vector<vector<int>> right(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      int rolling = 0;
      for (int j = m - 1; j >= 0; j--) {
        if (s[i][j] == '*') {
          right[i][j] = ++rolling;
        } else {
          rolling = 0;
        }
      }
    }
    vector<vector<int>> dp(n + 1, vector<int>(m));
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i + 1][j] = min({dp[i][j] + 1, left[i][j], right[i][j]});
        cnt += dp[i + 1][j];
      }
    }
    cout << cnt << '\n';
  }
}