#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector grid(101, vector<int>(101));
  vector<array<int, 4>> a(n);
  for (auto& [x1, x2, y1, y2] : a) {
    cin >> x1 >> x2 >> y1 >> y2;
    for (int xx = x1; xx < x2; xx++) {
      for (int yy = y1; yy < y2; yy++) {
        grid[xx][yy] = 1;
      }
    }
  }
  int res = 0;
  for (auto& row : grid) res += accumulate(row.begin(), row.end(), 0);
  cout << res << "\n";
}
