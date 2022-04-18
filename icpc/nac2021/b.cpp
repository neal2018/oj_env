#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const char nl = '\n';

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> grid(n + 2, vector<int>(m + 2));
  FOR(i, k) {
    int x, y;
    cin >> x >> y;
    grid[x][y]++;
  }

  vector<vector<int>> colpref(n + 2, vector<int>(m + 2));
  vector<vector<int>> rowpref(n + 2, vector<int>(m + 2));
  vector<vector<int>> pref2d(n + 2, vector<int>(m + 2));
  vector<vector<int>> vis(n + 2, vector<int>(m + 2));

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      colpref[i][j] = colpref[i - 1][j] + grid[i][j];
      rowpref[i][j] = rowpref[i][j - 1] + grid[i][j];
    }
  auto ROWEXISTS = [&](int idx, int l, int r) {
    return (rowpref[idx][r] - rowpref[idx][l - 1]) > 0;
  };

  auto COLEXISTS = [&](int idx, int u, int d) {
    return (colpref[d][idx] - colpref[u - 1][idx]) > 0;
  };

  auto check = [&](int s) {
    FOR(i, n + 2) FOR(j, m + 2) {
      vis[i][j] = 0;
      pref2d[i][j] = 0;
    }

    int sx = -1, sy = -1;
    for (int i = 1; i <= n; i++) {
      bool brk = false;
      for (int j = 1; j <= m; j++) {
        if (!grid[i][j]) {
          sx = i, sy = j;
          brk = true;
          break;
        }
      }
      if (brk) break;
    }

    bool ok = true;
    for (int i = sx; i < sx + s; i++) {
      bool brk = false;
      for (int j = sy; j < sy + s; j++) {
        if (i > n || j > m) {
          ok = false;
          brk = true;
          break;
        }
        if (grid[i][j]) {
          ok = false;
          brk = true;
          break;
        }
      }
      if (brk) break;
    }
    if (!ok) return false;

    deque<pii> q = {{sx, sy}};
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop_front();
      pref2d[r][c]++;
      pref2d[r + s][c]--;
      pref2d[r][c + s]--;
      pref2d[r + s][c + s]++;
      vis[r][c]++;

      // UP
      if (r > 1 && !ROWEXISTS(r - 1, c, c + s - 1)) {
        if (!vis[r - 1][c]) {
          vis[r - 1][c]++;
          q.push_back({r - 1, c});
        }
      }

      // DOWN
      if (r + s <= n && !ROWEXISTS(r + s, c, c + s - 1)) {
        if (!vis[r + 1][c]) {
          vis[r + 1][c]++;
          q.push_back({r + 1, c});
        }
      }

      // LEFT
      if (c > 1 && !COLEXISTS(c - 1, r, r + s - 1)) {
        if (!vis[r][c - 1]) {
          vis[r][c - 1]++;
          q.push_back({r, c - 1});
        }
      }

      // RIGHT
      if (c + s <= m && !COLEXISTS(c + s, r, r + s - 1)) {
        if (!vis[r][c + 1]) {
          vis[r][c + 1]++;
          q.push_back({r, c + 1});
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      int curpref = 0;
      for (int j = 1; j <= m; j++) {
        curpref += pref2d[i][j];
        pref2d[i][j] = curpref + pref2d[i - 1][j];
        if (!grid[i][j] && !pref2d[i][j]) ok = false;
      }
    }

    return ok;
  };

  int lo = 1, hi = min(n, m);
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  if (hi == 0) hi = -1;

  cout << hi << '\n';
}