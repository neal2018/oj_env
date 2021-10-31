#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a;
  cin >> T;
  auto solve = [&] {
    if (a == 2) {
      cout << 3 << '\n';
      return;
    }
    ll left = 0, right = min(a, (ll)1e8);
    while (left < right) {
      ll mid = (left + right + 1) / 2;
      if ((1 + mid) * mid / 2 > a) {
        right = mid - 1;
      } else {
        left = mid;
      }
    }
    ll t = (1 + right) * (right) / 2;
    if (t == a) {
      cout << right << '\n';
    } else {
      cout << right + (a - t + right - 2) / (right - 1) << '\n';
    }
  };
  while (T--) {
    cin >> a;
    solve();
  }
}