#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  int a = 0, b = 0, c = 0, res = 0;
  for (int _ = 0; _ < n; _++) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x) c = 3, res += 3;
    if (y && b + 1 + c < 3) res += 2 - b - c, c += 2 - b - c;
    if (z && a + 1 + b + 1 + c < 3) res += 1 - a - b - c, c += 1 - a - b - c;
    // cout << a << " " << b << " " << c << "\n";
    a = b, b = c, c = 0;
  }
  cout << res << "\n";
}