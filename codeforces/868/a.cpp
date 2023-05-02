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
    [&] {
      for (int t = 0; t <= n; t++) {
        if (t * (t - 1) + (n - t) * (n - t - 1) == 2 * k) {
          cout << "YES\n";
          for (int i = 0; i < t; i++) {
            cout << "1 ";
          }
          for (int i = t; i < n; i++) {
            cout << "-1 ";
          }
          cout << "\n";
          return;
        }
      }
      cout << "NO\n";
    }();
  }
}
