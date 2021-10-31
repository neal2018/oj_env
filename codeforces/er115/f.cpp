#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, ans = 0;
  cin >> n;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<int> sum(n), mini(n);
  vector<map<int, int>> mp(n);
  for (int i = 0; i < n; i++)
    for (auto& x : a[i]) {
      x == '(' ? sum[i]++ : sum[i]--;
      mini[i] = min(mini[i], sum[i]);
      if (mini[i] == sum[i]) mp[i][sum[i]]++;
    }
  vector<int> dp(1 << n, -1e9);
  dp[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    int p = 0;
    for (int j = 0; j < n; j++)
      if (i & 1 << j) p += sum[j];
    if (p < 0) continue;
    for (int j = 0; j < n; j++)
      if ((i & 1 << j) == 0) {
        int nex_i = i | 1 << j;
        if (p > -mini[j]) {
          dp[nex_i] = max(dp[nex_i], dp[i]);
        } else if (p == -mini[j]) {
          dp[nex_i] = max(dp[nex_i], dp[i] + mp[j][mini[j]]);
        } else {
          ans = max(ans, dp[i] + mp[j][-p]);
        }
        ans = max(ans, dp[nex_i]);
      }
  }
  cout << ans << '\n';
}