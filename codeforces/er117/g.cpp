#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto lcs = [&](string& s1, string& s2) {
    int n = s1.size(), m = s2.size();
    vector dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s1[i] == s2[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
      }
    }
    string res;
    return res;
  };
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
  }
}