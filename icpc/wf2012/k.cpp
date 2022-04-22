#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

const auto PI = acos(-1);
constexpr ld eps = 1e-12;
constexpr ll inf = 5e18;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  ll T = 1, n;
  while (cin >> n) {
    cout << "Case " << T << ": ";
    vector<vector<ll>> a(n);
    vector<ll> compress;
    for (auto& v : a) {
      ll k;
      cin >> k;
      ll pre = -1;
      for (ll i = 0, x; i < k; i++) {
        cin >> x;
        if (x != pre) {
          compress.push_back(x);
          v.push_back(x);
        }
        pre = x;
      }
    }
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    ll sz = compress.size();
    vector<vector<ll>> is_in(n, vector<ll>(sz));
    vector<ll> cnt(sz);
    // cout << sz << "\n";
    for (int i = 0; i < n; i++) {
      auto& v = a[i];
      for (auto& x : v) {
        x = lower_bound(compress.begin(), compress.end(), x) - compress.begin();
        is_in[i][x] = 1;
        cnt[x]++;
      }
    }
    vector<vector<ll>> dp(sz, vector<ll>(n, inf));
    for (int j = 0; j < n; j++) {
      if (is_in[j][0]) dp[0][j] = cnt[0];
    }
    for (int i = 1; i < sz; i++) {
      for (int j = 0; j < n; j++) {
        if (!is_in[j][i]) continue;
        for (int k = 0; k < n; k++) {
          // cout << "i=" << i << " j=" << j << " k=" << k << "\n";
          if (!is_in[k][i - 1]) continue;
          if (is_in[k][i] && (k != j || cnt[i] == 1)) {
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + cnt[i] - 1);
          } else {
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + cnt[i]);
          }
        }
      }
    }
    // for (int i = 0; i < sz; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    ll mini = inf;
    for (int i = 0; i < n; i++) {
      mini = min(mini, dp[sz - 1][i]);
    }
    cout << 2 * mini - n - 1 << "\n";
    T++;
  }
}
