#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  n = min(n, m + 1);
  while (k--) {
    ll x;
    cin >> x;
    ll left = 1, right = n;
    while (left < right) {
      ll mid = (left + right + 1) / 2;
      if (mid * mid <= x) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    if ((1 + left + 2 * m) * left / 2 >= x) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}