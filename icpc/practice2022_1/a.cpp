#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, d, maxi = 0, res = 0;
  cin >> n >> d;
  vector<array<ll, 3>> a(n);
  for (auto& [w, l, h] : a) cin >> l >> w >> h, maxi = max(maxi, w);
  sort(a.begin(), a.end(), greater());
  vector<ll> dp(maxi + 1);
  for (auto& [w, l, h] : a) {
    if (l + dp[w] > d) res++;
    for (int i = 1; i < w; i++) {
      dp[i] = max(dp[i], h);
      if (i + w <= maxi) dp[i] = max(dp[i], dp[i + w] + h);
    }
  }
  cout << res << "\n";
}