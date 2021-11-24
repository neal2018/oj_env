#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, k, x;
  cin >> T;
  while (T--) {
    cin >> k >> x;
    auto check = [&](ll mid) {
      mid--;
      if (mid <= k) return (mid + 1) * (mid) / 2;
      mid -= k;
      return (k + 1) * k / 2 + (k - 1 + k - mid) * mid / 2;
    };
    ll l = 1, r = 2 * k - 1;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (check(mid) < x) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << '\n';
  }
}