#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<ll>(m));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    auto func = [&](ll start){
      vector dp(n, vector<ll>(m, inf));
      dp[0][0] = a[0][0] - start;
      for (auto i : views::iota(0, n)) {
        for (auto j : views::iota(0, m)) {
          if (a[i][j] >= start + i + j) {
            ll need = a[i][j] - (start + i + j);
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + need);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + need);
          }
        }
      }
      return dp[n - 1][m - 1];
    };
    ll res = inf;
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        ll start = a[i][j] - i - j;
        if (start <= a[0][0]) {
          res = min(res, func(start));
        }
      }
    }
    cout << res << "\n";
  }
}
