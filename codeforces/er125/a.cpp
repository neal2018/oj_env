#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      cout << "0\n";
    } else {
      ll z = x * x + y * y;
      ll ss = (ll)sqrt(z);
      if (ss * ss == z) {
        cout << "1\n";
      } else {
        cout << "2\n";
      }
    }
  }
}
