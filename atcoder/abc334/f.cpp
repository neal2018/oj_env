#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll n, k, sx, sy;
  cin >> n >> k >> sx >> sy;
  // dp[i] = min(dp[j] + cost(j+1, i) for j in [i-k...i-1])
  // dp[i] = min(dp[j] + dist(o, j+1) + ... + dist(i-1, i) + dist(i, o) for j in [i-k...i-1])
  // pre_dist[i] = dist(0, 1) + dist(1, 2) + ... + dist(i-1, i)
  // dp[i] = min(dp[j] + dist(o, j+1) + dist(i, o) + pre_dist[i] - pre_dist[j+1] for j in
  //          [i-k...i-1])
  // dp[i] = min(dp[j] + dist(o, j+1) - pre_dist[j+1] for j in [i-k...i-1]) + dist(i, o) +
  //          pre_dist[i]
  vector<array<ll, 2>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;

  auto dist = [&](int x, int y) {
    if (x == -1) {
      return sqrt((sx - a[y][0]) * (sx - a[y][0]) + (sy - a[y][1]) * (sy - a[y][1]));
    }
    return sqrt((a[x][0] - a[y][0]) * (a[x][0] - a[y][0]) +
                (a[x][1] - a[y][1]) * (a[x][1] - a[y][1]));
  };

  vector<double> dp(n), pre_dist(n);
  for (int i = 1; i < n; i++) pre_dist[i] = pre_dist[i - 1] + dist(i - 1, i);

  set<pair<double, int>> st{pair{dist(-1, 0), -1}};
  for (int i = 0; i < n; i++) {
    auto [last_info, last_i] = *st.begin();
    while (last_i < i - k) {
      st.erase(st.begin());
      tie(last_info, last_i) = *st.begin();
    }

    dp[i] = last_info + dist(-1, i) + pre_dist[i];
    if (i != n - 1) {
      st.insert(pair{dp[i] + dist(-1, i + 1) - pre_dist[i + 1], i});
    }
  }
  cout << dp[n - 1] << "\n";
}
