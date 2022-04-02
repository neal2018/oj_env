#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef pair<int, int> ii;

const int MX = 2e5 + 5;
ll dp[MX][102];
int prect[101], sufct[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int n, k;
  cin >> n >> k;
  int arr[n + 1];
  int remain = 0;
  memset(sufct, 0, sizeof sufct);
  FOR(i, n) {
    cin >> arr[i + 1];
    if (arr[i + 1]) sufct[arr[i + 1]]++;
    if (!arr[i + 1]) remain++;
  }

  memset(prect, 0, sizeof prect);
  memset(dp, -1, sizeof dp);
  dp[0][k + 1] = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] != 0) {
      ll contr = 0;
      for (int j = 1; j <= k; j++) {
        if (j > arr[i]) contr += prect[j];
      }
      for (int j = 1; j <= k + 1; j++) {
        if (dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][j] + contr;
      }
      prect[arr[i]]++;
      sufct[arr[i]]--;
    } else {
      int biggerbefore = 0;
      int smallerafter = 0;
      ll besttrans = -1;
      for (int l = 1; l < k; l++) smallerafter += sufct[l];
      for (int l = k; l >= 1; l--) {
        if (dp[i - 1][k + 1] != -1) dp[i][l] = dp[i - 1][k + 1] + biggerbefore + smallerafter;
        if (dp[i - 1][l] != -1)
          dp[i][l] = max(dp[i][l], dp[i - 1][l] + biggerbefore + smallerafter);
        if (besttrans != -1)
          dp[i][l] = max(dp[i][l], besttrans + biggerbefore + smallerafter + remain);
        biggerbefore += prect[l];
        smallerafter -= sufct[l - 1];
        besttrans = max(besttrans, dp[i - 1][l]);
      }
      remain--;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= k + 1; i++) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << '\n';
}
