#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  // ll n;
  // cin >> n;
  vector<vector<pair<int, int>>> res;
  for (int n = 1; n <= 19; n++) {
    int cnt = 0;
    vector<pair<int, int>> directions = {{1, 3},  {3, 1},  {-1, 3},  {3, -1},
                                         {1, -3}, {-3, 1}, {-1, -3}, {-3, -1}};
    int nice = 0;
    while (cnt++ < 50000 * n) {
      vector<pair<int, int>> his;
      vector<int> row(n);
      vector<int> col(n);
      int x = rng() % n;
      int y = rng() % n;
      if (n >= 10) x = 0, y = 0;
      row[x] = 1, col[y] = 1;
      his.push_back({x, y});
      // x = 3, y = 1;
      // row[x] = 1, col[y] = 1;
      // his.push_back({x, y});
      while (true) {
        shuffle(directions.begin(), directions.end(), rng);
        if (![&] {
              for (auto& [dx, dy] : directions) {
                int xx = x + dx, yy = y + dy;
                if (!(0 <= xx && xx < n && 0 <= yy && yy < n && row[xx] == 0 && col[yy] == 0)) {
                  continue;
                }
                x = xx, y = yy;
                row[x] = 1, col[y] = 1;
                his.push_back({x, y});
                return true;
              }
              return false;
            }()) {
          break;
        }
      }
      if (n == 10 && his.back() != pair{n - 1, n - 1}) continue;
      if (accumulate(row.begin(), row.end(), 0) == n &&
          accumulate(col.begin(), col.end(), 0) == n) {
        cout << "GOOD " << n << "\n";
        nice = 1;
        res.push_back(his);
        break;
      }
    }
    if (!nice) {
      cout << "END " << n << "\n";
      res.push_back({});
    }
  }
  cout << "{";
  for (int i = 0; i < res.size(); i++) {
    cout << "{";
    for (auto& [xx, yy] : res[i]) {
      cout << "{" << xx << "," << yy << "},";
    }
    cout << "},";
  }
  cout << "}";
}
