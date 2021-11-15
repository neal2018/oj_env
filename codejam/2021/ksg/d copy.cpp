#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, a;
  cin >> T;
  // auto solve = [&] {
  // };
  for (ll ttt = 1; ttt <= T; ttt++) {
    cout << "Case #" << ttt << ": ";
    cin >> n >> a;
    if (a < n - 2) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    cout << "POSSIBLE\n";
    if (n == 3) {
      cout << 0 << ' ' << 0 << '\n';
      cout << 0 << ' ' << 1 << '\n';
      cout << a << ' ' << 0 << '\n';
    } else if (n == 4) {
      cout << 0 << ' ' << 0 << '\n';
      cout << 0 << ' ' << 1 << '\n';
      cout << (a + 1) / 2 << ' ' << 1 << '\n';
      cout << a / 2 << ' ' << 0 << '\n';
    } else if (n == 5) {
      cout << 0 << ' ' << 0 << '\n';
      cout << 0 << ' ' << 1 << '\n';
      cout << (a - 1) / 2 << ' ' << 1 << '\n';
      cout << a / 2 + 1 << ' ' << 2 << '\n';
      cout << (a - 1) / 2 << ' ' << 0 << '\n';
    } else {
      int k = 0;
      for (int i = 0; i < (n - 2) / 2; i++, k = 1 - k) {
        cout << i << ' ' << k << '\n';
      }
      k = 1 - k;
      if (n % 2 == 0) {
        cout << (a + 1) / 2 << ' ' << k << '\n';
        cout << a / 2 << ' ' << k + 1 << '\n';
      } else {
        cout << (a - 1) / 2 << ' ' << k << '\n';
        cout << a / 2 + 1 << ' ' << k + 2 << '\n';
        cout << (a - 1) / 2 << ' ' << k + 1 << '\n';
      }

      for (int i = (n - 2) / 2 - 1; i >= 0; i--, k = 1 - k) {
        cout << i << ' ' << k + 1 << '\n';
      }
    }
  }
  return 0;
}