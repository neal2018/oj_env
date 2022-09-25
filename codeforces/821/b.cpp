#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;
    if ((x && y) || (x || y) == 0) {
      cout << "-1\n";
      continue;
    }
    if (x == 0) swap(x, y);
    if ((n - 1) % x != 0) {
      cout << "-1\n";
      continue;
    }
    for (int cur = 1; cur <= n;) {
      for (int t = 0; t < x; t++) {
        cout << cur << " ";
      }
      if (cur == 1) cur++;
      cur += x;
    }
    cout << "\n";
  }
}
