#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    vector color(n, vector(m, -1));
    vector<pair<int, int>> directions = {{1, 0}, {0, 1},  {-1, 0}, {0, -1},
                                         {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    function<void(int, int, int)> dfs = [&](int i, int j, int c) {
      color[i][j] = c;
      for (auto [di, dj] : directions) {
        int ii = i + di, jj = j + dj;
        if (0 <= ii && ii < n && 0 <= jj && jj < m) {
          if (color[ii][jj] == -1 && a[ii][jj] == '*') dfs(ii, jj, c);
        }
      }
    };
    int id = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '*' && color[i][j] == -1) {
          dfs(i, j, id), id++;
        }
      }
    }
    vector<vector<pair<int, int>>> group(id);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (color[i][j] != -1) group[color[i][j]].push_back({i, j});
      }
    }
    cout << ([&] {
      for (auto& v : group) {
        if (v.size() != 3) return false;
        set<int> st_x, st_y;
        for (auto& [x, y] : v) st_x.insert(x), st_y.insert(y);
        if (st_x.size() != 2 || st_y.size() != 2) return false;
      }
      return true;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}
