#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int r = 0, b = 0, g = 0, f = 1;
    string s;
    cin >> s;
    for (auto& c : s) {
      if (c == 'r') {
        r++;
      } else if (c == 'b') {
        b++;
      } else if (c == 'g') {
        g++;
      } else if (c == 'R') {
        r--;
      } else if (c == 'B') {
        b--;
      } else if (c == 'G') {
        g--;
      }
      if (r < 0 || b < 0 || g < 0) {
        f = 0;
        break;
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
