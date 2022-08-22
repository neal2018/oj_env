#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> compress;
  vector a(n, vector<int>(n));
  for (auto& r : a) {
    for (auto& x : r) cin >> x, compress.push_back(x);
  }
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());

  int m = int(compress.size());
  if (k >= m) {
    cout << k - m << "\n";
    return 0;
  }
  if (k == 1) {
    cout << "1\n";
    return 0;
  }

  vector<array<int, 4>> p(m, {inf, -inf, inf, -inf});
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = int(lower_bound(compress.begin(), compress.end(), a[i][j]) - compress.begin());
      p[x][0] = min(p[x][0], i);
      p[x][1] = max(p[x][1], i);
      p[x][2] = min(p[x][2], j);
      p[x][3] = max(p[x][3], j);
    }
  }

  for (int len = 1; len < n; len++) {
    vector c(n + 1, vector<int>(n + 1));
    for (auto& [x_min, x_max, y_min, y_max] : p) {
      int x1 = max(0, x_max - len + 1);
      int y1 = max(0, y_max - len + 1);
      int x2 = min(n, x_min + 1);
      int y2 = min(n, y_min + 1);
      if (x1 < x2 && y1 < y2) {
        c[x1][y1]++, c[x2][y2]++, c[x2][y1]--, c[x1][y2]--;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n; j++) c[i][j] += c[i][j - 1];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) c[i][j] += c[i - 1][j];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (c[i][j] == m - k || c[i][j] == m - k + 1) {
          cout << "1\n";
          return 0;
        }
      }
    }
  }
  cout << "2\n";
}
