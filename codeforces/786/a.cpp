#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll x, y;
    cin >> x >> y;
    if (y < x || y % x) {
      cout << "0 0\n";
    } else {
      ll z = y / x;
      cout << "1 " << z << "\n";
    }
  }
}
