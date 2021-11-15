#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, a;
  cin >> T;
  // auto solve = [&] {
  // };
  for (ll ttt = 1; ttt <= T; ttt++) {
    cout << "Case #" << ttt << ": ";
    cin >> n >> a;
    if (n == 3) {
      cout << "POSSIBLE\n";
      cout << 0 << ' ' << 0 << '\n';
      cout << 0 << ' ' << 1 << '\n';
      cout << a << ' ' << 0 << '\n';
    } else if (n == 4) {
      if (a < 2) {
        cout << "IMPOSSIBLE\n";
      } else {
        cout << "POSSIBLE\n";
        cout << 0 << ' ' << 0 << '\n';
        cout << 0 << ' ' << 1 << '\n';
        cout << (a + 1) / 2 << ' ' << 1 << '\n';
        cout << a / 2 << ' ' << 0 << '\n';
      }
    } else if (n == 5) {
      if (a < 3) {
        cout << "IMPOSSIBLE\n";
      } else {
        cout << "POSSIBLE\n";
        cout << 0 << ' ' << 0 << '\n';
        cout << 0 << ' ' << 1 << '\n';
        cout << (a - 1) / 2 << ' ' << 1 << '\n';
        cout << a / 2 + 1 << ' ' << 2 << '\n';
        cout << (a - 1) / 2 << ' ' << 0 << '\n';
      }
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
  return 0;
}