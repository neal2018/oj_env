#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  string need = "snuke";
  vector<pair<int, int>> directions = {{1, 0},  {0, 1},  {1, 1},  {-1, 0},
                                       {0, -1}, {-1, 1}, {1, -1}, {-1, -1}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto get = [&](int di, int dj) -> vector<pair<int, int>> {
        int k = 0;
        int x = i, y = j;
        vector<pair<int, int>> res;
        while (k < need.size()) {
          if (!(0 <= x && x < n && 0 <= y && y < m)) return {};
          if (a[x][y] != need[k]) return {};
          res.push_back({x, y});
          x += di, y += dj, k++;
        }
        return res;
      };
      for (auto& [di, dj] : directions) {
        auto res = get(di, dj);
        if (res.size()) {
          for (auto& [x, y] : res) {
            cout << x + 1 << " " << y + 1 << "\n";
          }
          return 0;
        }
      }
    }
  }
}
