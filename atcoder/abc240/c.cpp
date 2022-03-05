#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, t;
  cin >> n >> t;
  vector<pair<ll, ll>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  vector<int> dp(t + 1);
  dp[0] = 1;
  for (auto& [x, y] : a) {
    vector<int> ndp(t + 1);
    for (int i = t; i >= 0; i--) {
      if (i >= x) ndp[i] |= dp[i - x];
      if (i >= y) ndp[i] |= dp[i - y];
    }
    dp = ndp;
  }
  cout << (dp.back() ? "Yes\n" : "No\n");
}
