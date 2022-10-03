#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> b(n);
  for (auto& x : b) cin >> x;
  vector a(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    int t = b[i];
    for (int j = 0; j < n; j++) {
      a[i][(i + j) % n] = (t + i * j) % n;
    }
  }
  // for (int c1 = 0; c1 < n; c1++) {
  //   for (int c2 = c1 + 1; c2 < n; c2++) {
  //     for (int r1 = 0; r1 < n; r1++) {
  //       for (int r2 = r1 + 1; r2 < n; r2++) {
  //         if ((a[r1][c1] + a[r2][c2]) % n == (a[r1][c2] + a[r2][c1]) % n) {
  //           assert(false);
  //         }
  //       }
  //     }
  //   }
  // }
  for (auto& r : a) {
    for (auto& x : r) cout << x << " ";
    cout << "\n";
  }
}
