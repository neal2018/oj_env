#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> pre(n, -1), dp(n, -1);
    vector<ll> last(26, -1);
    for (int i = 0; i < n; i++) {
      if (last[s[i] - 'a'] != -1) {
        pre[i] = last[s[i] - 'a'];
      }
      last[s[i] - 'a'] = i;
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      dp[i] = dp[i - 1] + 1;
      if (pre[i] != -1) {
        ll from = pre[i] == 0 ? 0 : dp[pre[i] - 1];
        dp[i] = min(dp[i], from + (i - pre[i] - 1));
      }
    }
    cout << dp[n - 1] << "\n";
  }
}
