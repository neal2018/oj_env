#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<string> g(n);
    for (auto& x : g) cin >> x;
    int lx = 0, ly = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (g[i][j] == 'L') lx = i, ly = j;
    set<pair<int, int>> seen;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    function<void(int, int)> dfs = [&](int i, int j) {
      int cnt = 0;
      for (auto [di, dj] : directions) {
        int ii = i + di, jj = j + dj;
        if (0 <= ii && ii < n && 0 <= jj && jj < m 
            && g[ii][jj] == '.') cnt++;
      }
      if (cnt > 1 && g[i][j] != 'L') return;
      if (g[i][j] != 'L') g[i][j] = '+';
      seen.insert({i, j});
      for (auto [di, dj] : directions) {
        int ii = i + di, jj = j + dj;
        if (0 <= ii && ii < n && 0 <= jj && jj < m 
            && g[ii][jj] != '#' && seen.count({ii, jj}) == 0)
          dfs(ii, jj);
      }
    };
    dfs(lx, ly);
    for (auto& x : g) cout << x << '\n';
  }
}
