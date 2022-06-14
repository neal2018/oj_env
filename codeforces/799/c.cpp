#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    [] {
      vector<string> a(8);
      for (auto& x : a) cin >> x;
      int pre = -1, pos = 0;
      for (int i = 0; i < 8; i++) {
        int cur = 0, cur_pre = -1, left = 0, right = 0;
        for (int j = 0; j < 8; j++) {
          if (a[i][j] == '#') {
            if (cur_pre == -1) {
              cur_pre = j;
            } else {
              cur = cur_pre - j;
            }
            left += (j < pos);
            right += (j > pos);
          }
        }
        if (pre == 0 && cur == -2 && left == 1 && right == 1) {
          cout << i << " " << pos + 1 << "\n";
          return;
        }
        pos = cur_pre, pre = cur;
      }
      cout << 8 << " " << pos + 1 << "\n";
    }();
  }
}
