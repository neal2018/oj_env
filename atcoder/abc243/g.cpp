#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MAX = 1e6;

ll get_sqrt(ll x) {
  ll l = 1, r = x;
  while (l < r) {
    ll mid = l + (r - l + 1) / 2;
    if ((__int128)mid * mid <= x) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<ll> dp(MAX), pre(MAX);
  dp[1] = 1, pre[2] = 1;
  for (int i = 2; i < MAX; i++) {
    ll sqr = get_sqrt(i);
    dp[i] = pre[sqr + 1];
    pre[i + 1] = pre[i] + dp[i];
  }

  int T;
  cin >> T;
  while (T--) {
    ll x;
    cin >> x;
    if (x < MAX) {
      cout << dp[x] << "\n";
    } else {
      ll sqr = get_sqrt(x);
      if (sqr < MAX) {
        cout << pre[sqr + 1] << "\n";
      } else {
        // dp[1] + ... + dp[sqr]
        // dp[i] = pre[sqrt(i)+1]
        ll res = 0;
        for (ll l = 1, r; l <= sqr; l = r + 1) {
          ll root = get_sqrt(l);
          r = min(sqr, (root + 1) * (root + 1) - 1);
          res += (r - l + 1) * pre[root + 1];
        }
        cout << res << "\n";
      }
    }
  }
}
