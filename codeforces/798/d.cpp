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
    vector a(n, vector<int>(m));
    auto left = a, right = a, up = a, down = a;
    for (auto& r : a) {
      for (char c; auto& x : r) {
        cin >> c, x = (c == 'B');
      }
    }
    // left
    for (auto i : views::iota(0, n) | views::reverse) {
      for (auto j : views::iota(0, m)) {
        for (auto [di, dj] : {pair{1, 0}, pair{0, -1}}) {
          int ii = i + di, jj = j + dj;
          if (!(0 <= ii && ii < n && 0 <= jj && jj < m)) continue;
          if (a[ii][jj] || left[ii][jj]) left[i][j] = max(left[i][j], left[ii][jj] + 1);
        }
      }
    }
    // right
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m) | views::reverse) {
        for (auto [di, dj] : {pair{-1, 0}, pair{0, 1}}) {
          int ii = i + di, jj = j + dj;
          if (!(0 <= ii && ii < n && 0 <= jj && jj < m)) continue;
          if (a[ii][jj] || right[ii][jj]) right[i][j] = max(right[i][j], right[ii][jj] + 1);
        }
      }
    }
    // up
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        for (auto [di, dj] : {pair{-1, 0}, pair{0, -1}}) {
          int ii = i + di, jj = j + dj;
          if (!(0 <= ii && ii < n && 0 <= jj && jj < m)) continue;
          if (a[ii][jj] || up[ii][jj]) up[i][j] = max(up[i][j], up[ii][jj] + 1);
        }
      }
    }
    // down
    for (auto i : views::iota(0, n) | views::reverse) {
      for (auto j : views::iota(0, m) | views::reverse) {
        for (auto [di, dj] : {pair{1, 0}, pair{0, 1}}) {
          int ii = i + di, jj = j + dj;
          if (!(0 <= ii && ii < n && 0 <= jj && jj < m)) continue;
          if (a[ii][jj] || down[ii][jj]) down[i][j] = max(down[i][j], down[ii][jj] + 1);
        }
      }
    }
    int res = 1e9, x = -1, y = -1;
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        int cost = max({left[i][j], right[i][j], up[i][j], down[i][j]});
        if (cost < res) x = i, y = j, res = cost;
      }
    }
    cout << x + 1 << " " << y + 1 << "\n";
  }
}
