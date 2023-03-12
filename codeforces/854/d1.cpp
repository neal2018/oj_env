#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), cold(k), hot(k);
    for (auto& x : a) cin >> x, x--;
    for (auto& x : cold) cin >> x;
    for (auto& x : hot) cin >> x;
    vector<ll> dp(k + 1, inf);
    dp[k] = 0;
    for (int id = 0; id < n; id++) {
      auto x = a[id];
      vector<ll> ndp(k + 1, inf);

      // other one
      int prev = id == 0 ? k : a[id - 1];
      for (int i = 0; i <= k; i++) {
        if (i == x) {
          ndp[prev] = min(ndp[prev], dp[i] + hot[x]);
        } else {
          ndp[prev] = min(ndp[prev], dp[i] + cold[x]);
        }
      }

      // i-1 one
      for (int i = 0; i <= k; i++) {
        if (dp[i] == inf) continue;
        if (prev == x) {
          ndp[i] = min(ndp[i], dp[i] + hot[x]);
        } else {
          ndp[i] = min(ndp[i], dp[i] + cold[x]);
        }
      }
      swap(ndp, dp);
    }
    auto res = *min_element(dp.begin(), dp.end());
    cout << res << "\n";
  }
}
