#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int x, y, z;
  cin >> x >> y >> z;
  if (x < 0) x = -x, y = -y, z = -z;
  auto res = [&] {
    if (y > 0 && y < x) {
      if (z < y) {
        return abs(z) + abs(x - z);
      } else {
        return -1;
      }
    } else {
      return abs(x);
    }
  }();
  cout << res << "\n";
}
