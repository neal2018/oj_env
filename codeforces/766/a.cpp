#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n, m, xx, yy;
    cin >> n >> m >> xx >> yy;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    if (s[xx - 1][yy - 1] == 'B') {
      cout << 0 << "\n";
    } else {
      int f = 0;
      for (int i = 0; i < n; i++) {
        if (s[i][yy - 1] == 'B') f = 1;
      }
      for (int i = 0; i < m; i++) {
        if (s[xx - 1][i] == 'B') f = 1;
      }
      if (f) {
        cout << 1 << "\n";
        continue;
      }
      for (auto& x : s) {
        for (auto& c : x) {
          if (c == 'B') f = 1;
        }
      }
      cout << (f ? 2 : -1) << "\n";
    }
  }
}