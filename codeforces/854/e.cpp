#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    auto fill = [&] {
      while (true) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          int mini = -1, maxi = -1;
          for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
              mini = (mini == -1 ? j : mini);
              maxi = j;
            }
          }
          if (mini == -1) continue;
          for (int j = mini; j <= maxi; j++) {
            if (a[i][j] != '#') {
              cnt++, a[i][j] = '#';
            }
          }
        }
        for (int j = 0; j < m; j++) {
          int mini = -1, maxi = -1;
          for (int i = 0; i < n; i++) {
            if (a[i][j] == '#') {
              mini = (mini == -1 ? i : mini);
              maxi = i;
            }
          }
          if (mini == -1) continue;
          for (int i = mini; i <= maxi; i++) {
            if (a[i][j] != '#') {
              cnt++, a[i][j] = '#';
            }
          }
        }
        if (cnt == 0) break;
      }
    };
    fill();
    vector seen(n, vector<int>(m, -1));
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<array<int, 2>>> groups(2);
    function<void(int, int, int)> dfs = [&](int i, int j, int color) {
      groups[color].push_back({i, j});
      seen[i][j] = color;
      for (auto& [di, dj] : directions) {
        int ii = i + di, jj = j + dj;
        if (0 <= ii && ii < n && 0 <= jj && jj < m && a[ii][jj] == '#' && seen[ii][jj] == -1) {
          dfs(ii, jj, color);
        }
      }
    };
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (seen[i][j] == -1 && a[i][j] == '#') dfs(i, j, cnt++);
      }
    }
    if (cnt == 2) {
      auto get_matrix = [&](int c) {
        int x1 = n, y1 = m, x2 = 0, y2 = 0;
        for (auto& [i, j] : groups[c]) {
          x1 = min(x1, i), x2 = max(x2, i);
          y1 = min(y1, j), y2 = max(y2, j);
        }
        return array{x1, y1, x2, y2};
      };
      vector<pair<int, array<int, 4>>> mats = {{0, get_matrix(0)}, {1, get_matrix(1)}};
      if (mats[0].second[0] < mats[1].second[0]) {
        swap(mats[0], mats[1]);
      }
      if (mats[0].second[1] > mats[1].second[1]) {
        auto [c1, mat1] = mats[1];
        auto [c2, mat2] = mats[0];
        a[mat1[2]][mat1[3]] = '#';
        a[mat2[0]][mat2[1]] = '#';
        fill();
        int x = mat1[2], y = mat1[3];
        while (x < mat2[0]) {
          x++;
          a[x][y] = '#';
        }
        while (y < mat2[1]) {
          y++;
          a[x][y] = '#';
        }
      } else {
        auto [c1, mat1] = mats[0];
        auto [c2, mat2] = mats[1];
        a[mat1[0]][mat1[3]] = '#';
        a[mat2[2]][mat2[1]] = '#';
        fill();
        int x = mat1[0], y = mat1[3];
        while (x > mat2[2]) {
          x--;
          a[x][y] = '#';
        }
        while (y < mat2[1]) {
          y++;
          a[x][y] = '#';
        }
      }
    }
    for (auto& s : a) {
      cout << s << "\n";
    }
    cout << "\n";
  }
}
