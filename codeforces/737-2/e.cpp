#include <bits/stdc++.h>
using namespace std;
void solve() {
  cout << "1 1" << endl;
  int x = 1, y = 1, x1 = 1, y1 = 1, x2 = 8, y2 = 8;
  string move;
  while (true) {
    cin >> move;
    if (move == "Done") return;
    if (move.find("Right") != string::npos) y1++, y2++;
    if (move.find("Left") != string::npos) y1--, y2--;
    if (move.find("Up") != string::npos) x1--, x2--;
    if (move.find("Down") != string::npos) x1++, x2++;
    x1 = max(x1, 1), x2 = min(x2, 8);
    y1 = max(y1, 1), y2 = min(y2, 8);
    if (x1 == x) x1++;
    if (y1 == y) y1++;
    if (x2 == x) x2--;
    if (y2 == y) y2--;
    int nx = x, ny = y;
    if (x != x1 - 1) {
      nx = x + 1;
    } else if (y1 > 1 && y1 - 1 != y) {
      ny = y1 - 1;
    } else if (y2 < 8 && y2 + 1 != y) {
      ny = y2 + 1;
    } else if (y2 - y1 == 6) {
      ny = 2;
    } else {
      ny = 1;
    }
    x = nx, y = ny;
    cout << x << " " << y << endl;
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
