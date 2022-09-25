#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<string> a(10);
  for (auto& x : a) cin >> x;
  int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (a[i][j] == '#') {
        if (x1 == -1) x1 = i;
        if (y1 == -1) y1 = j;
        x2 = i, y2 = j;
      }
    }
  }
  cout << x1 + 1 << " " << x2 + 1 << "\n" << y1 + 1 << " " << y2 + 1 << "\n";
}
