#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m);
  for (auto& x : a) cin >> x;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  ll offset = max(n, m);
  ll res = 0;
  {
    vector<ll> dp(offset * 3);
    for (ll i = m - 1; i >= 0; i--) {
      dp[a[i] + i] = dp[a[i] + i + 1] + 1;
    }
    for (ll i = 0; i < n; i++) res += min(i + 1, m + 2 - dp[i]);
  }
  {
    vector<ll> dp(offset * 3);
    for (ll i = m - 1; i >= 0; i--) {
      dp[a[i] - i + offset] = dp[a[i] - i - 1 + offset] + 1;
    }
    for (ll i = 0; i < n; i++) res += min(n - i, m + 2 - dp[i + 2 + offset]);
  }
  cout << res - n << "\n";
}
