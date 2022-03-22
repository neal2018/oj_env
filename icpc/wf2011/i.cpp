#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const int MX = 155;
ll dp[MX][MX + 1];
ll nut[MX], reward[MX], suf[MX];

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  for (int i = 0; i < n; i++) cin >> nut[i] >> reward[i];

  suf[n] = 0;
  for (int i = n - 1; i >= 0; i--) suf[i] = reward[i] + suf[i + 1];

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= MX; j++) dp[i][j] = INF;

  dp[n][0] = -INF;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = MX - 1; j >= 0; j--) {
      vector<ll> cands = {dp[i][j + 1]};
      if (suf[i] - j + 1 >= 0 && suf[i] - j + 1 <= MX)
        cands.push_back(1 - dp[i + 1][suf[i] - j + 1] - nut[i]);
      cands.push_back(max((ll)1, dp[i + 1][j] + nut[i] + 1));
      sort(cands.begin(), cands.end());
      dp[i][j] = cands[0];
    }
  }

  int ans = 0;
  for (int i = 0; i < MX; i++)
    if (dp[0][i] <= a - b) ans = i;
  cout << ans << ' ' << suf[0] - ans << '\n';
}
