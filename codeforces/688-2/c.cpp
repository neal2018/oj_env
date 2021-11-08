#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    for (int d = 0; d < 10; d++) {
      int res = 0;
      // each row
      {
        int first_d = n, last_d = -1;
        for (int i = 0; i < n; i++) {
          if (a[i].find(d + '0') != string::npos) {
            first_d = min(first_d, i);
            last_d = max(last_d, i);
          }
        }
        for (int i = 0; i < n; i++) {
          int left_d = n, right_d = -1;
          for (int j = 0; j < n; j++) {
            if (a[i][j] == d + '0') {
              left_d = min(left_d, j);
              right_d = max(right_d, j);
            }
          }
          int maxi_width = max(right_d, n - 1 - left_d);
          res = max({res, (right_d - left_d) * i, (right_d - left_d) * (n - 1 - i)});
          if (maxi_width > 0) {
            res = max({res, maxi_width * (i - first_d), maxi_width * (last_d - i)});
          }
        }
      }
      // each col
      {
        int first_d = n, last_d = -1;
        for (int j = 0; j < n; j++) {
          for (int i = 0; i < n; i++) {
            if (a[i][j] == d + '0') {
              first_d = min(first_d, j);
              last_d = max(last_d, j);
            }
          }
        }
        for (int j = 0; j < n; j++) {
          int left_d = n, right_d = -1;
          for (int i = 0; i < n; i++) {
            if (a[i][j] == d + '0') {
              left_d = min(left_d, i);
              right_d = max(right_d, i);
            }
          }
          int maxi_width = max(right_d, n - 1 - left_d);
          res = max({res, (right_d - left_d) * j, (right_d - left_d) * (n - 1 - j)});
          if (maxi_width > 0) {
            res = max({res, maxi_width * (j - first_d), maxi_width * (last_d - j)});
          }
        }
        cout << res << ' ';
      }
    }
    cout << '\n';
  }
}