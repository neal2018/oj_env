#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, c, d;
  cin >> T;
  while (T--) {
    cin >> c >> d;
    if (abs(c - d) % 2 == 1) {
      cout << -1 << '\n';
    } else if (c == 0 && d == 0) {
      cout << 0 << '\n';
    } else if (c == d) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
}