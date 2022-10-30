#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int good = 1, n;
  cin >> n;
  vector<vector<int>> g(10, vector<int>(10));
  for (int _ = 0; _ < n; _++) {
    int d, l, r, c;
    cin >> d >> l >> r >> c, r--, c--;
    if (d == 0) {
      if (c + l > 10) good = 0;
      for (int j = c; j < min(10, c + l); j++) {
        if (g[r][j]) good = 0;
        g[r][j] = 1;
      }
    } else {
      if (r + l > 10) good = 0;
      for (int i = r; i <min(10, r + l); i++) {
        if (g[i][c]) good = 0;
        g[i][c] = 1;
      }
    }
  }
  cout << (good ? "Y\n" : "N\n");
}
