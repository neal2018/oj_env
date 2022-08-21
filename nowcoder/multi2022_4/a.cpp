#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr int FACTOR = 10000;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> a(n);
  for (auto& [x, y] : a) cin >> x;
  for (auto& [x, y] : a) cin >> y;
  // w1 + q1w2 > w2 + q2w1
  sort(a.begin(), a.end(), [&](auto& x, auto& y) {
    return x.first * FACTOR + x.second * y.first > y.first * FACTOR + y.second * x.first;
  });
  vector<ld> dp(m);
  for (int i = n - 1; i >= 0; i--) {
    auto [w, q] = a[i];
    for (int j = m - 1; j >= 0; j--) {
      if (j == 0) {
        dp[j] = max(dp[j], (ld)w);
      } else {
        dp[j] = max(dp[j], dp[j - 1] * q / FACTOR + w);
      }
    }
  }
  ld res = *max_element(dp.begin(), dp.end());
  cout << res << "\n";
}
