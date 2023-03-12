#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector res(n, string(n, '.'));
  vector point(n + 1, vector<int>(n + 1));
  vector<tuple<char, array<int, 4>>> order = {
      {'U', {0, 0, 0, 1}},
      {'L', {0, 0, 1, 0}},
      {'D', {1, 0, 1, 1}},
      {'R', {0, 1, 1, 1}},
  };
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (auto& [c, shift] : order) {
        auto [dx1, dy1, dx2, dy2] = shift;
        int x1 = i + dx1;
        int y1 = j + dy1;
        int x2 = i + dx2;
        int y2 = j + dy2;
        if (point[x1][y1] || point[x2][y2]) {
          continue;
        }
        point[x1][y1] = 1;
        point[x2][y2] = 1;
        res[i][j] = c;
        cnt++;
        break;
      }
    }
  }
  // cout << cnt << "\n";
  // cout << (n + 1) * (n + 1) / 2 << "\n";
  for (auto& s : res) cout << s << "\n";
}
