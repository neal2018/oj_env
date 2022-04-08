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
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<string> black(n), to(n);
    for (auto& x : black) cin >> x;
    for (auto& x : to) cin >> x;
    vector<int> dfn(n * m, -1), seen(n * m);
    int res_circle = 0, res_black = 0;
    int node_x = -1, node_y = -1, len = -1;
    auto get_to = [&](int x, int y) {
      if (to[x][y] == 'U') {
        x--;
      } else if (to[x][y] == 'D') {
        x++;
      } else if (to[x][y] == 'L') {
        y--;
      } else {
        y++;
      }
      return pair{x, y};
    };
    function<void(int, int, int)> dfs = [&](int x, int y, int dep) {
      if (node_x != -1) return;
      if (dfn[x * m + y] != -1) {
        node_x = x, node_y = y, len = dep - dfn[x * m + y];
        return;
      }
      dfn[x * m + y] = dep;
      auto [nx, ny] = get_to(x, y);
      dfs(nx, ny, dep + 1);
    };
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto check = [&](int i, int j, int _len) {
      vector<int> cnt(_len);
      function<void(int, int, int)> color = [&](int x, int y, int dep) {
        if (seen[x * m + y]) return;
        seen[x * m + y] = 1;
        if (black[x][y] == '0') cnt[dep % len] = 1;
        for (auto& [dx, dy] : directions) {
          int xx = x + dx, yy = y + dy;
          if (0 <= xx && xx < n && 0 <= yy && yy < m && seen[xx * m + yy] == 0) {
            auto [px, py] = get_to(xx, yy);
            if (px == x && py == y) color(xx, yy, dep + 1);
          }
        }
      };
      color(i, j, 0);
      return accumulate(cnt.begin(), cnt.end(), 0);
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        node_x = -1;
        if (!seen[i * m + j]) {
          dfs(i, j, 0);
          res_circle += len;
          res_black += check(node_x, node_y, len);
        }
      }
    }
    cout << res_circle << " " << res_black << "\n";
  }
}
