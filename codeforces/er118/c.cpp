#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, h;
  cin >> T;
  while (T--) {
    cin >> n >> h;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    auto check = [&](ll k) {
      ll total = 0, pre = a[0];
      for (int i = 0; i < n; i++) {
        total += min(k, a[i] - pre);
        pre = a[i];
      }
      total += k;
      return total >= h;
    };
    ll l = 1, r = h;
    while (l < r) {
      ll mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r << '\n';
  }
}