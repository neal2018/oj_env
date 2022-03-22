#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, q;
  cin >> n >> m >> q;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<array<ll, 4>> queries(q);
  for (int i = 0; i < q; i++) {
    auto& [t, x, y, ii] = queries[i];
    cin >> x >> y >> t, ii = i, x--, y--, t--;
  }
  sort(queries.begin(), queries.end());
  vector<int> res(q);
  auto pre = a;
  vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  ll cur = 0, period = -1, t = 0;
  for (; cur < q; t++) {
    int change_cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int f = 1;
        for (auto& [di, dj] : directions) {
          int ii = i + di, jj = j + dj;
          if (0 <= ii && ii < n && 0 <= jj && jj < m) {
            f &= (pre[i][j] ^ pre[ii][jj]);
            if (!f) break;
          }
        }
        if (!f) {
          a[i][j] = (a[i][j] == '0' ? '1' : '0');
          change_cnt++;
        }
      }
    }
    while (cur < q && queries[cur][0] == t) {
      auto& [tt, x, y, ii] = queries[cur];
      res[ii] = a[x][y] - '0';
      cur++;
    }
    for (auto& s : a) cout << s << "\n";
    cout << "\n";
    if (change_cnt == 0) {
      period = 1;
      break;
    }
    if (t > 0 && change_cnt == n * m) {
      period = 2;
      break;
    }
    pre = a;
  }
  // cout << t << "\n";
  for (; cur < q; cur++) {
    auto& [tt, x, y, ii] = queries[cur];
    if (period == 1) {
      res[ii] = a[x][y] - '0';
    } else if (period == 2) {
      if ((tt - t) % 2 == 0) {
        res[ii] = a[x][y] - '0';
      } else {
        res[ii] = pre[x][y] - '0';
      }
    } else {
      assert(false);
    }
  }
  for (auto& x : res) cout << x << "\n";
}
