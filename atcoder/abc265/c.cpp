#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  int i = 0, j = 0;
  set<pair<int, int>> seen;
  while (true) {
    int ii = -1, jj = -1;
    if (a[i][j] == 'U' && i != 0) ii = i - 1, jj = j;
    if (a[i][j] == 'D' && i != n - 1) ii = i + 1, jj = j;
    if (a[i][j] == 'L' && j != 0) ii = i, jj = j - 1;
    if (a[i][j] == 'R' && j != m - 1) ii = i, jj = j + 1;
    if (ii == -1 && jj == -1) {
      cout << i + 1 << " " << j + 1 << "\n";
      return 0;
    }
    if (seen.count({ii, jj})) {
      cout << "-1\n";
      return 0;
    }
    seen.insert({ii, jj});
    i = ii, j = jj;
  }
}
