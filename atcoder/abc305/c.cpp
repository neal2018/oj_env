#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  array<array<int, 2>, 4> directions = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') continue;
      int cnt = 0;
      for (auto& [di, dj] : directions) {
        int ii = i + di, jj = j + dj;
        if (0 <= ii && ii < n && 0 <= jj && jj < m) {
          if (a[ii][jj] == '#') cnt++;
        }
      }
      if (cnt >= 2) {
        cout << i + 1 << " " << j + 1 << "\n";
      }
    }
  }
}
