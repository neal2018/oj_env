#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    constexpr int n = 10;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 'X') {
          auto ii = i, jj = j;
          if (ii > 4) ii = 9 - i;
          if (jj > 4) jj = 9 - j;
          auto add = 5 - max(4 - ii, 4 - jj);
          res += add;
        }
      }
    }
    cout << res << "\n";
  }
}
