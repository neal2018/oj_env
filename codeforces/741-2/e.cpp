#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  string s;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    vector<vector<ll>> lcp(n + 1, vector<ll>(n + 1));
    // lcp[i][j]: lcp of s[i...n-1], s[j...n-1], j>=i
    for (ll i = n - 1; i >= 0; i--) {
      for (ll j = n - 1; j >= i; j--) {
        if ((s[i] == s[j])) lcp[i][j] = 1 + lcp[i + 1][j + 1];
      }
    }
    vector<ll> dp(n);
    for (ll i = 0; i < n; i++) {
      dp[i] = n - i;
      for (ll j = 0; j < i; j++) {
        if (s[i] > s[j]) {
          dp[i] = max(dp[i], dp[j] + n - i);
        } else if (s[i] == s[j]) {
          ll l = lcp[j][i];
          if (l == n - j || (l < n - i && s[i + l] > s[j + l])) {
            dp[i] = max(dp[i], dp[j] + n - i - l);
          }
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
  }
}
