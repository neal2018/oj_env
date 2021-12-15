#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n), b;
  for (auto& x : a) cin >> x;
  ranges::sort(a);
  ll ans = 1e18;
  for (int k = 0; k < n; k++) {
    ll res = 0, maxi = 0, mini = 1e9;
    for (int t = 0; t < n; t++) {
      ll i = (t + k) % n;
      maxi = max(maxi, a[i]);
      mini = min(mini, a[i]);
      res += maxi - mini;
    }
    ans = min(ans, res);
  }
  cout << ans << '\n';
}