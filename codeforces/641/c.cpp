#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 9e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, qq;
  cin >> n >> m >> qq;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<ll>> dist(n, vector<ll>(m, inf));
  vector<vector<int>> seen(n, vector<int>(m));
  vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<pair<int, int>> q, nq;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int f = 1;
      for (auto& [di, dj] : directions) {
        int ii = i + di, jj = j + dj;
        if (0 <= ii && ii < n && 0 <= jj && jj < m) {
          f &= (a[i][j] ^ a[ii][jj]);
          if (!f) {
            q.push_back({i, j});
            seen[i][j] = 1;
            dist[i][j] = 0;
            break;
          }
        }
      }
    }
  }
  for (int step = 0; q.size(); swap(q, nq), nq.clear(), step++) {
    for (auto& [i, j] : q) {
      for (auto& [di, dj] : directions) {
        int ii = i + di, jj = j + dj;
        if (0 <= ii && ii < n && 0 <= jj && jj < m && seen[ii][jj] == 0) {
          nq.push_back({ii, jj});
          seen[ii][jj] = 1;
          dist[ii][jj] = step + 1;
        }
      }
    }
  }
  while (qq--) {
    ll x, y, t;
    cin >> x >> y >> t, x--, y--;
    if (t <= dist[x][y]) {
      cout << a[x][y] << "\n";
    } else {
      if ((dist[x][y] - t) % 2 == 0) {
        cout << a[x][y] << "\n";
      } else {
        cout << (a[x][y] == '0' ? '1' : '0') << "\n";
      }
    }
  }
}
