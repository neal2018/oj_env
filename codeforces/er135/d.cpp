#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = int(s.size());
    vector dp(n + 1, vector<int>(n + 1));
    for (int len = 1; len <= n; len++) {
      for (int l = 0; l + len <= n; l++) {
        int r = l + len;
        if (len == 1) {
          dp[l][r] = s[l] - 'a';
        } else if (len % 2) {
          auto t1 = dp[l + 1][r];
          auto t2 = dp[l][r - 1];
          auto c1 = s[l] - 'a';
          auto c2 = s[r - 1] - 'a';
          if (t1 == -2 || t2 == -2) {
            dp[l][r] = -1;
          } else if (t1 == -3 || t2 == -3) {
            dp[l][r] = 1e5;
            if (t1 == -3) dp[l][r] = min(dp[l][r], c1);
            if (t2 == -3) dp[l][r] = min(dp[l][r], c2);
          } else {
            dp[l][r] = -2;
          }
        } else {
          auto t1 = dp[l + 1][r];
          auto t2 = dp[l][r - 1];
          auto c1 = s[l] - 'a';
          auto c2 = s[r - 1] - 'a';
          if (t1 == -2 || t2 == -2) {
            dp[l][r] = -1;
          } else if (t1 > c1 || t2 > c2) {
            dp[l][r] = -1;
          } else if (t1 == c1 || t2 == c2) {
            dp[l][r] = -3;
          } else {
            dp[l][r] = -2;
          }
        }
      }
    }
    if (dp[0][n] == -1) {
      cout << "Alice\n";
    } else if (dp[0][n] == -2) {
      cout << "Bob\n";
    } else {
      cout << "Draw\n";
    }
  }
}
