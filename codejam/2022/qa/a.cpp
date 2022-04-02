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
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ":\n";
    ll r, c;
    cin >> r >> c;
    for (int i = 0; i < 2 * r + 1; i++) {
      for (int j = 0; j < 2 * c + 1; j++) {
        if (i < 2 && j < 2) {
          cout << ".";
        } else {
          if (i % 2 == 0) {
            cout << (j % 2 == 0 ? "+" : "-");
          } else {
            cout << (j % 2 == 0 ? "|" : ".");
          }
        }
      }
      cout << "\n";
    }
  }
}