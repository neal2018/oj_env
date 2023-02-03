#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    cout << ([&] {
      for (auto& c : s) {
        if (c == 'U') {
          y++;
        } else if (c == 'D') {
          y--;
        } else if (c == 'L') {
          x--;
        } else {
          x++;
        }
        if (x == 1 && y == 1) return true;
      }
      return false;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}
