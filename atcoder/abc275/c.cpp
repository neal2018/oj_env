#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<string> a(9);
  int res = 0;
  for (auto& x : a) cin >> x;
  for (int x1 = 0; x1 < 9; x1++) {
    for (int y1 = 0; y1 < 9; y1++) {
      for (int di = 0; di < 9; di++) {
        for (int dj = 1; dj < 9; dj++) {
          int x2 = x1 + di, y2 = y1 + dj;
          int x3 = x2 + dj, y3 = y2 - di;
          int x4 = x3 - di, y4 = y3 - dj;
          if (!((0 <= x2 && x2 < 9 && 0 <= y2 && y2 < 9) &&
                (0 <= x3 && x3 < 9 && 0 <= y3 && y3 < 9) &&
                (0 <= x4 && x4 < 9 && 0 <= y4 && y4 < 9)))
            continue;
          if (set<pair<int, int>>{{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}}.size() != 4) continue;
          if (a[x1][y1] == '#' && a[x2][y2] == '#' && a[x3][y3] == '#' && a[x4][y4] == '#') {
            res++;
            // cout << x1 << " " << y1 << " \n";
            // cout << x2 << " " << y2 << " \n";
            // cout << x3 << " " << y3 << " \n";
            // cout << x4 << " " << y4 << " \n\n";
          }
        }
      }
    }
  }
  cout << res << "\n";
}
