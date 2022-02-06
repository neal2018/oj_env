#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    ll l, r, k;
    cin >> l >> r >> k;
    if (l == r) {
      if (l == 1) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      if (l % 2 == 0) l++;
      if (r % 2 == 0) r--;
      if (k > (r - l) / 2) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}