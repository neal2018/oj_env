#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  int f = 0;
  for (int i = 0; i < n && !f; i++) {
    for (int j = 0; j < n && !f; j++) {
      if (i + 6 <= n) {
        int cnt = 0;
        for (int k = i; k < i + 6; k++) {
          cnt += (a[k][j] == '.');
        }
        if (cnt <= 2) f = 1;
      }
      // cout << i << " " << j << " " << f << "\n";

      if (j + 6 <= n) {
        int cnt = 0;
        for (int k = j; k < j + 6; k++) {
          cnt += (a[i][k] == '.');
        }
        if (cnt <= 2) f = 1;
      }
      // cout << i << " " << j << " " << f << "\n";

      if (j + 6 <= n && i + 6 <= n) {
        int cnt = 0;
        for (int k = 0; k < 6; k++) {
          cnt += (a[i + k][j + k] == '.');
        }
        if (cnt <= 2) f = 1;
      }
      // cout << i << " " << j << " " << f << "\n";

      if (j - 5 >= 0 && i + 6 <= n) {
        int cnt = 0;
        for (int k = 0; k < 6; k++) {
          cnt += (a[i + k][j - k] == '.');
        }
        if (cnt <= 2) f = 1;
      }
      // cout << i << " " << j << " " << f << "\n";
    }
  }
  cout << (f ? "Yes\n" : "No\n");
}
