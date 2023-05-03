#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> conds(k);
    for (auto& [x, y] : conds) cin >> x;
    for (auto& [x, y] : conds) cin >> y;
    string res(n, '?');
    char c = 'd';
    [&] {
      int prev_loc = 3, prev_cnt = 3;
      for (auto [loc, cnt] : conds) {
        if (loc <= 3) {
          if (cnt != loc) {
            cout << "NO\n";
            return;
          }
        } else {
          int need = cnt - prev_cnt;
          int len = loc - prev_loc;
          if (need > len) {
            cout << "NO\n";
            return;
          }
          for (int i = 0; i < need; i++) {
            res[prev_loc + i] = c;
          }
          c++;
          prev_loc = loc, prev_cnt = cnt;
        }
      }
      for (int i = 0, shift = 0; i < n; i++) {
        if (res[i] == '?') {
          res[i] = char('a' + shift);
          shift = (shift + 1) % 3;
        }
      }
      cout << "YES\n";
      cout << res << "\n";
    }();
  }
}
