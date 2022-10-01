#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int even_cnt = 0;
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      x = (x % 2 + 2) % 2;
      if (x == 0) even_cnt++;
    }
    vector dp1(n + 1, vector<array<int, 2>>(n + 1));
    vector dp2(n + 1, vector<array<int, 2>>(n + 1));
    dp1[0][0][0] = 1;
    dp1[0][0][1] = 0;
    dp2[0][0][0] = 1;
    dp2[0][0][1] = 0;
    for (int total = 1; total <= n; total++) {
      for (int even = 0; even <= total; even++) {
        for (int t : {0, 1}) {
          // if alice go first
          dp1[total][even][t] = 0;
          if (even != total) {
            dp1[total][even][t] |= dp2[total - 1][even][t ^ 1];
          }
          if (even) {
            dp1[total][even][t] |= dp2[total - 1][even - 1][t];
          }
          // second
          dp2[total][even][t] = 1;
          if (even != total) {
            dp2[total][even][t] &= dp1[total - 1][even][t];
          }
          if (even) {
            dp2[total][even][t] &= dp1[total - 1][even - 1][t];
          }
        }
      }
    }
    cout << (dp1[n][even_cnt][0] == 1 ? "Alice" : "Bob") << "\n";
  }
}
