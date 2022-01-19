#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, inf = 1e18;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  vector<vector<vector<ll>>> dp(n, {{inf, inf}, {inf, inf}});
  dp[0][0][0] = a[0], dp[0][1][1] = 0;  // 0: same as mid
  for (int i = 1; i < n; i++) {
    for (int j : {0, 1}) {
      for (int k : {0, 1}) {
        for (int pre : {0, 1}) {
          dp[i][j][k] =
              min(dp[i][j][k], dp[i - 1][j][pre] + (k == pre) * b[i - 1] + (k == 0) * a[i]);
        }
      }
    }
  }
  ll res = inf;
  for (int j : {0, 1}) {
    for (int k : {0, 1}) {
      res = min(res, dp[n - 1][j][k] + (j == k) * b[n - 1]);
    }
  }
  cout << res << "\n";
}
