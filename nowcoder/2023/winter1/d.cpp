#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int x, y, xp, yp;
    cin >> x >> y >> xp >> yp;
    auto inter = [&](int x1, int y1, int x2, int y2) {
      return max(0, min(x, x2) - max(0, x1)) * max(0, min(y, y2) - max(0, y1));
    };
    auto common = [&](int x1, int y1, int x2, int y2) {
      return x * y + (x2 - x1) * (y2 - y1) - inter(x1, y1, x2, y2);
    };
    long double res = 0;
    auto calc = [&](int x1, int y1, int x2, int y2) {
      if (x2 < x1) swap(x1, x2);
      if (y2 < y1) swap(y1, y2);
      long double cur = inter(x1, y1, x2, y2) * 1.0 / common(x1, y1, x2, y2);
      res = max(res, cur);
    };
    calc(xp, yp, x, y);
    calc(xp, yp, x, 0);
    calc(xp, yp, 0, y);
    calc(xp, yp, 0, 0);
    cout << fixed << setprecision(10);
    cout << res << "\n";
  }
}