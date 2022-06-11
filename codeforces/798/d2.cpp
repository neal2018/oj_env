#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, total = 0;
    cin >> n >> m;
    vector<vector<int>> a(n + m, vector<int>(n + m));
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        char c;
        cin >> c;
        if (c == 'B') total++, a[i + j][i - j + m] = 1;
      }
    }
    vector pre(n + m + 1, vector<int>(n + m + 1));
    for (auto i : views::iota(0, n + m)) {
      int cur = 0;
      for (auto j : views::iota(0, n + m)) {
        cur += a[i][j];
        pre[i + 1][j + 1] = cur + pre[i][j + 1];
      }
    }
    int pos_x = -1, pos_y = -1;
    auto check = [&](int mid) {
      for (auto i : views::iota(0, n)) {
        for (auto j : views::iota(0, m)) {
          int x = i + j, y = i - j + m;
          int lx = max(x - mid, 0), rx = min(x + mid + 1, n + m);
          int ly = max(y - mid, 0), ry = min(y + mid + 1, n + m);
          if (pre[rx][ry] + pre[lx][ly] - pre[rx][ly] - pre[lx][ry] >= total) {
            pos_x = i, pos_y = j;
            return true;
          }
        }
      }
      return false;
    };
    int l = 0, r = n + m - 2;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    check(r);
    cout << pos_x + 1 << " " << pos_y + 1 << "\n";
  }
}
