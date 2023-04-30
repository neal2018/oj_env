#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<int> res(min(n, m) + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#' && (i == 0 || j == 0 || (a[i - 1][j - 1] == '.'))) {
        int x = i, y = j;
        while ((x + 1 < n) && (y + 1 < m) && (a[x + 1][y + 1] == '#')) {
          x++, y++;
        }
        int len = (x - i) / 2;
        res[len]++;
      }
    }
  }
  for (int i = 1; i < min(n, m) + 1; i++) cout << res[i] << " ";
  cout << "\n";
}
