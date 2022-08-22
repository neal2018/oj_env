#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int x, y, n;
  cin >> x >> y >> n;
  if (3 * x <= y) {
    cout << n * x << "\n";
  } else {
    cout << n / 3 * y + (n % 3) * x << "\n";
  }
}
