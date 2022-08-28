#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr int MAX = 1e5 + 10;
constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<array<ll, 5>> a(MAX), dp(MAX, {-inf, -inf, -inf, -inf, -inf});
  dp[0][0] = 0;
  for (ll i = 0, t, x, sz; i < n; i++) {
    cin >> t >> x >> sz;
    a[t][x] += sz;
  }
  for (int i = 1; i < MAX; i++) {
    for (int j = 0; j < 5; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
      if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
      if (j < 4) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + a[i][j]);
    }
  }
  cout << *max_element(dp.back().begin(), dp.back().end()) << "\n";
}
