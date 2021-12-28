#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, xx, y;
  cin >> n >> xx >> y;
  vector<ll> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  vector<ll> dp(1 << n, 1e18);
  dp[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    int done = __builtin_popcount(i);
    for (int t = 0, cnt = 0; t < n; t++) {
      if ((i & (1 << t)) == 0) {
        dp[i | (1 << t)] = min(dp[i | (1 << t)], dp[i] + cnt * y + abs(b[done] - a[t]) * xx);
        cnt++;
      }
    }
  }
  cout << dp.back() << '\n';
}
