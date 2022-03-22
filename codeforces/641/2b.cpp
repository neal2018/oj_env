#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
      for (int j = 0; (j + 1) * (j + 1) <= (i + 1); j++) {
        if ((i + 1) % (j + 1) == 0) {
          if (a[j] < a[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
          }
          if (a[(i + 1) / (j + 1) - 1] < a[i]) {
            dp[i] = max(dp[i], dp[(i + 1) / (j + 1) - 1] + 1);
          }
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
  }
}
