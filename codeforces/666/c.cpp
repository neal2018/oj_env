#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll dp0 = 0, dp1 = 1e18;
  for (int i = 0; i < n; i++) {
    auto x = a[i];
    ll ndp0 = min(dp0 + x * r1 + r3, dp1 + d + min((x + 2) * r1, r2 + r1));
    ll ndp1 = dp0 + d + min((x + 2) * r1, r2 + r1);
    if (i == n - 1) ndp0 = min(ndp0, dp1 + x * r1 + r3);
    dp0 = ndp0, dp1 = ndp1;
  }
  cout << min(dp0, dp1 + d) + d * (n - 1) << "\n";
}
