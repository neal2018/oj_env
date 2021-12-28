#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> b(n, vector<int>(n));
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y, x--, y--;
    a[x][y] = 1;
    a[y][x] = 1;
  }
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y, x--, y--;
    b[x][y] = 1;
    b[y][x] = 1;
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  do {
    int f = 1;
    for (int i = 0; i < n && f; i++) {
      for (int j = 0; j < n && f; j++) {
        if (a[p[i]][p[j]] != b[i][j]) {
          f = 0;
        }
      }
    }
    if (f) {
      cout << "Yes\n";
      return 0;
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << "No\n";
}