#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i], cin >> b[i], a[i] %= k;
  }
  vector<ll> dp(k, -1);
  for (int i = 0; i < n; i++) {
    vector<ll> ndp = dp;
    for (int j = 0; j < k; j++) {
      if (dp[j] == -1) continue;
      ll nex = (j + a[i]) % k;
      ndp[nex] = max(ndp[nex], dp[j] + b[i]);
    }
    ndp[a[i]] = max(ndp[a[i]], b[i]);
    dp = ndp;
  }
  cout << dp[0] << "\n";
}
