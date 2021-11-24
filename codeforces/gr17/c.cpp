#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  auto f = [&]() {
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      // a[i] = min(a[i], n - (i + 1));
      // b[i] = min(b[i], i);
    }
    ll l = 1, r = n;
    auto check = [&](ll mid) {
      ll cnt = 0;
      for (ll i = 0; i < n; i++) {
        if (a[i] >= mid - cnt - 1 && b[i] >= cnt) {
          cnt++;
        }
      }
      return cnt >= mid;
    };
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << "\n";
  };
  while (T--) {
    f();
  }
}