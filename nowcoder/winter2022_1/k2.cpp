#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  // 0, 1, 2 : R, G, B
  auto color = [&](int a, int b, int c) {
    int cnt[3] = {};
    cnt[a]++, cnt[b]++, cnt[c]++;
    if (cnt[1] > cnt[0]) return 'G';
    if (cnt[0] > cnt[1]) return 'R';
    return 'B';
  };
  vector<vector<ll>> dp(n, vector<ll>(27, -1));
  for (int i = 0; i < n; i++) {
    if (s[i] == 'X') {
      for (int j = 0; j < 27; j++) {
        int a = j / 9, b = (j / 3) % 3, c = j % 3;
        if (i == 0) dp[i][j] = (c == 1);
        if (i == 1) dp[i][j] = (b == 1) + (c == 1);
      }
    } else {
      for (int j = 0; j < 27; j++) {
        int a = j / 9, b = (j / 3) % 3, c = j % 3;
        if (color(a, b, c) == s[i]) {
          for (int pre_a = 0; pre_a < 3; pre_a++) {
            int pre = pre_a * 9 + a * 3 + b;
            if (dp[i - 1][pre] != -1) {
              dp[i][j] = max(dp[i][j], dp[i - 1][pre] + (c == 1));
            }
          }
        }
      }
    }
  }
  ll maxi = -1;
  for (int i = 0; i < 27; i++) {
    maxi = max(maxi, dp[n - 1][i]);
  }
  cout << maxi << "\n";
}