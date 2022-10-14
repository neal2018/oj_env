#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n = 8;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    vector<int> col(n), row(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] != '.') {
          auto t = a[i][j] == 'R' ? 1 : -1;
          col[i] += t, row[i] += t;
        }
      }
    }
    [&] {
      for (auto& x : col) {
        if (x == 8) {
          cout << "R\n";
          return;
        }
      }
      for (auto& x : row) {
        if (x == 8) {
          cout << "R\n";
          return;
        }
      }
      cout << "B\n";
    }();
  }
}
