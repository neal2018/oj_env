#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    int f = 1;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        if (j > 0 && a[i][j] == '0' && a[i][j - 1] == '1' && a[i + 1][j] == '1' &&
            a[i + 1][j - 1] == '1')
          f = 0;
        if (j < m - 1 && a[i][j] == '0' && a[i][j + 1] == '1' && a[i + 1][j] == '1' &&
            a[i + 1][j + 1] == '1')
          f = 0;
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j > 0 && a[i][j] == '0' && a[i][j - 1] == '1' && a[i - 1][j] == '1' &&
            a[i - 1][j - 1] == '1')
          f = 0;
        if (j < m - 1 && a[i][j] == '0' && a[i][j + 1] == '1' && a[i - 1][j] == '1' &&
            a[i - 1][j + 1] == '1')
          f = 0;
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
