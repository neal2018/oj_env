#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k, p;
  cin >> n >> k >> p;
  ll max_n = 1;

  auto base = p + 1;
  for (ll i = 0; i < k; i++) max_n *= base;
  vector<ll> dp(max_n, -1);
  dp[0] = 0;
  for (ll _ = 0; _ < n; _++) {
    ll c;
    cin >> c;
    vector<ll> a(k);
    for (auto& x : a) cin >> x;
    auto ndp = dp;
    for (ll i = 0; i < max_n; i++) {
      if (dp[i] == -1) continue;
      vector<ll> cur;
      {
        auto t = i;
        for (ll ii = 0; ii < k; ii++) {
          cur.push_back(t % base);
          t /= base;
        }
      }
      for (ll ii = 0; ii < k; ii++) {
        cur[ii] += a[ii];
        if (cur[ii] >= p) cur[ii] = p;
      }
      ll to = 0;
      ll cur_base = 1;
      for (auto& x : cur) {
        to += cur_base * x;
        cur_base *= base;
      }
      if (ndp[to] == -1) {
        ndp[to] = dp[i] + c;
      } else {
        ndp[to] = min(ndp[to], dp[i] + c);
      }
    }
    dp = ndp;
  }
  cout << dp[max_n - 1] << "\n";
}
