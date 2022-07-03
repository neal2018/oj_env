#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll m;
  cin >> m;
  vector<ll> a(m);
  for (auto& x : a) cin >> x;
  int pos = 0;
  for (int i = 0; i < m; i++) {
    if (a[pos] * (i + 1) > a[i] * (pos + 1)) pos = i;
  }
  vector<ll> dp(m * m + 1, 1e18);
  dp[0] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m * m + 1; j++) {
      dp[j] = min(dp[j], dp[j - i - 1] + a[i]);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    ll n;
    cin >> n;
    ll extra = max(n - m * m, 0ll);
    ll res = (extra + pos) / (pos + 1) * a[pos];
    n -= (extra + pos) / (pos + 1) * (pos + 1);
    cout << res + dp[n] << "\n";
  }
}
