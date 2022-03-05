#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, t;
    cin >> n >> t;
    vector<ll> a(n), dp(n);
    for (auto& x : a) cin >> x;
    dp[0] = a[0];
    for (int j = 1; j < n; j++) {
      dp[j] = max(0ll, dp[j - 1]) + a[j];
    }
    cout << max(*max_element(dp.begin(), dp.end()), 0ll) << " ";
    for (int i = 0; i < n; i++) {
      vector<ll> ndp(n);
      ndp[0] = a[0] + t;
      for (int j = 1; j < n; j++) {
        ndp[j] = max(0ll, dp[j - 1]) + a[j] + t;
      }
      dp = ndp;
      cout << max(*max_element(dp.begin(), dp.end()), 0ll) << " ";
    }
    cout << "\n";
  };
}
