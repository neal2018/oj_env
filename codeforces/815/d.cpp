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
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
      for (int j = max(0, i - 1000); j < i; j++) {
        if ((a[j] ^ i) < (a[i] ^ j)) {
          // cout << "connect " << i << " " << j << "\n";
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    // for (auto& x : dp) cout << x << " ";
    // cout << "\n";
    cout << ranges::max(dp) << "\n";
  }
}
