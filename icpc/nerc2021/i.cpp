#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int dig(int r, int c) {
  int res;
  cout << "DIG " << r + 1 << " " << c + 1 << endl;
  cin >> res;
  return res;
}
int scan(int r, int c) {
  int res;
  cout << "SCAN " << r + 1 << " " << c + 1 << endl;
  cin >> res;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int a = scan(0, 0);
    int b = scan(0, m - 1);
    int x_plus = (a + b) / 2 - (m - 1);
    int y_plus = (a - b) / 2 + (m - 1);
    int c = scan(x_plus / 2, 0);
    int d = scan(0, y_plus / 2);
    int x1 = (x_plus + (c - y_plus)) / 2;
    int x2 = (x_plus - (c - y_plus)) / 2;
    int y1 = (y_plus + (d - x_plus)) / 2;
    int y2 = (y_plus - (d - x_plus)) / 2;
    if (!dig(x1, y1)) {
      dig(x1, y2), dig(x2, y1);
    } else {
      dig(x2, y2);
    }
  }
}