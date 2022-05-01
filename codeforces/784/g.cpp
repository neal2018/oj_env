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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    for (int j = 0; j < m; j++) {
      int cnt = 0, pre = -1;
      for (int i = 0; i < n; i++) {
        if (a[i][j] == '*') {
          cnt++;
        } else if (a[i][j] == 'o') {
          for (int k = pre + 1; k < i - cnt; k++) a[k][j] = '.';
          for (int k = i - cnt; k < i; k++) a[k][j] = '*';
          pre = i;
          cnt = 0;
        }
      }
      int i = n;
      for (int k = pre + 1; k < i - cnt; k++) a[k][j] = '.';
      for (int k = i - cnt; k < i; k++) a[k][j] = '*';
    }
    for (auto& x : a) cout << x << "\n";
    cout << "\n";
  }
}
