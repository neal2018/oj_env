#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  vector<ll> dp1(n), dp2(n);
  dp1[0] = 1, dp2[0] = 1;
  for (int i = 1; i < n; i++) {
    if (abs(a[i] - a[i - 1]) <= k) dp1[i] |= dp1[i - 1];
    if (abs(a[i] - b[i - 1]) <= k) dp1[i] |= dp2[i - 1];
    if (abs(b[i] - b[i - 1]) <= k) dp2[i] |= dp2[i - 1];
    if (abs(b[i] - a[i - 1]) <= k) dp2[i] |= dp1[i - 1];
  }
  if (dp1[n - 1] || dp2[n - 1]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
