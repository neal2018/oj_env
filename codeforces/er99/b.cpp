#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll x;
    cin >> x;
    ll l = 0, r = x;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (mid * (mid + 1) / 2 <= x) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    ll cur = l * (l + 1) / 2, res = l;
    while (cur < x) {
      cur += (res - 1);
      res++;
    }
    cout << res << "\n";
  }
}
