#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, x, y;
  cin >> T;
  while (T--) {
    cin >> x >> y;
    if ((x + y) & 1) {
      cout << "-1 -1\n";
    } else {
      ll mid = (x + y) / 2;
      if (x > y) {
        cout << mid << " 0\n";
      } else {
        cout << "0 " << mid << "\n";
      }
    }
  }
}