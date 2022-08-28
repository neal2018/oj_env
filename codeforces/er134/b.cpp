#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, sx, sy, dd;
    cin >> n >> m >> sx >> sy >> dd, sx--, sy--;
    bool a = (sx - dd) <= 0;
    bool b = (sx + dd) >= n - 1;
    bool c = (sy - dd) <= 0;
    bool d = (sy + dd) >= m - 1;
    if ((a || d) && (b || c)) {
      cout << "-1\n";
    } else {
      cout << n + m - 2 << "\n";
    }
  }
}
