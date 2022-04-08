#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    ll x = (a + c - 1) / c, y = (b + d - 1) / d;
    if (x + y > k) {
      cout << "-1\n";
    } else {
      cout << x << " " << y << "\n";
    }
  }
}
