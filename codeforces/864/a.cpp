#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    ll res = 4;
    if (x1 != x2) {
      res = min(res, m);
    }
    if (y1 != y2) {
      res = min(res, n);
    }
    if (((x1 == 1 || x1 == n) && (y1 == 1 || y1 == m))) {
      res = min(res, 2ll);
    }
    if (((x2 == 1 || x2 == n) && (y2 == 1 || y2 == m))) {
      res = min(res, 2ll);
    }

    if (((x1 == 1 || x1 == n) || (y1 == 1 || y1 == m))) {
      res = min(res, 3ll);
    }
    if (((x2 == 1 || x2 == n) || (y2 == 1 || y2 == m))) {
      res = min(res, 3ll);
    }
    cout << res << "\n";
  }
}
