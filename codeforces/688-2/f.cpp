#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr int inf = 1e9;
int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> dp(n, inf);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
      int cnt = 0;
      for (int j = i + 1; j < n && j <= i + a[i]; j++) {
        if (dp[j] != -1) {
          cnt++;
          dp[i] = min(dp[i], dp[j]);
        }
      }
      if (dp[i] != inf) {
        dp[i] += (cnt - 1);
      } else {
        dp[i] = -1;
      }
    }
    cout << dp[0] << '\n';
  }
}