#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a > b) {
      swap(l, r);
      l = -l, r = -r, a = -a, b = -b;
    }
    a -= l, b -= l, r -= l;
    if (a == b) {
      cout << "0\n";
      continue;
    }
    if (b - a >= x) {
      cout << "1\n";
      continue;
    }
    int res = 3;
    if (a >= x && b >= x) {
      res = 2;
    }
    if (r - a >= x && r - b >= x) {
      res = 2;
    }
    if (res == 2) {
      cout << res << "\n";
    } else {
      if ((r < x) || (a < x && r - a < x) || (b < x && r - b < x)) {
        cout << "-1\n";
        continue;
      }
      cout << res << "\n";
    }
  }
}
