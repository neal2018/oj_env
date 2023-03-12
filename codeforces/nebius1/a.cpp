#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    x = abs(x), y = abs(y);
    if (x > y) swap(x, y);
    int res = x * 2;
    y -= x;
    res += max(y * 2 - 1, 0);
    cout << res << "\n";
  }
}
