#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int max_number = ranges::max(a);
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++) {
      int maxi = 0, len = 0;
      vector<int> freq(max_number + 1);
      for (int j = i - 1; j >= 0; j--) {
        // delete [j+1, i-1]
        if ((i == n || a[i] == a[j]) && dp[j]) {
          if (len % 2 == 0 && maxi <= len / 2) {
            dp[i] = max(dp[i], dp[j] + 1);
          }
        }
        len++, maxi = max(maxi, ++freq[a[j]]);
      }
      // delete [0, i-1]
      if (len % 2 == 0 && maxi <= len / 2) {
        dp[i] = max(dp[i], 1);
      }
    }
    cout << dp[n] - 1 << "\n";
  }
}
