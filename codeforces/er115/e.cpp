#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += 1;
      {  // right
        int nr = m - 1 - j;
        int nd = n - 1 - i;
        nr = min(nr, nd + 1);
        nd = min(nd, nr);
        ans += nr + nd;
      }
      {  // down
        int nr = m - 1 - j;
        int nd = n - 1 - i;
        nd = min(nd, nr + 1);
        nr = min(nr, nd);
        ans += nr + nd;
      }
    }
  }
  vector<vector<int>> a(n, vector<int>(m));
  auto solve = [&](int i, int j, int di, int dj) {
    int cc = 1;
    while (true) {
      i += di, j += dj;
      if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == 1) break;
      cc++, swap(di, dj);
    }
    return cc;
  };
  while (q--) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    {
      int x = solve(i, j, -1, 0), y = solve(i, j, 0, 1);
      ans += (a[i][j] == 1 ? 1 : -1) * x * y;
    }
    {
      int x = solve(i, j, 0, -1), y = solve(i, j, 1, 0);
      ans += (a[i][j] == 1 ? 1 : -1) * x * y;
    }
    ans += (a[i][j] == 1 ? -1 : 1);
    a[i][j] ^= 1;
    cout << ans << '\n';
  }
  return 0;
}