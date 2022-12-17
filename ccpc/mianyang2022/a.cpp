#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e18;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> b(n);
  for (auto& x : b) cin >> x;
  sort(a.begin(), a.end(), greater());
  sort(b.begin(), b.end(), greater());
  vector dp(2 * n + 1, vector(k + 1, vector(k + 1, 0ll)));
  for (int step = 2 * n - 1; step >= 0; step--) {
    for (int k1 = 0; k1 <= k; k1++) {
      for (int k2 = 0; k2 <= k; k2++) {
        int n1 = (step / 2 - k2) + k1, n2 = (step - step / 2 - k1) + k2;
        if (n1 < 0 || n2 < 0) continue;
        if (n1 > n || n2 > n) continue;
        if (step % 2 == 0) {
          dp[step][k1][k2] = -inf;
          if (n1 != n && k1 < k) {
            dp[step][k1][k2] = max(dp[step][k1][k2], dp[step + 1][k1 + 1][k2] + a[n1]);
          }
          if (n2 != n) {
            dp[step][k1][k2] = max(dp[step][k1][k2], dp[step + 1][k1][k2]);
          }
        } else {
          dp[step][k1][k2] = inf;
          if (n2 != n && k2 < k) {
            dp[step][k1][k2] = min(dp[step][k1][k2], dp[step + 1][k1][k2 + 1] - b[n2]);
          }
          if (n1 != n) {
            dp[step][k1][k2] = min(dp[step][k1][k2], dp[step + 1][k1][k2]);
          }
        }
      }
    }
  }
  cout << dp[0][0][0] << "\n";
}
