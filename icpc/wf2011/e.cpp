#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll dx, dy, n, q;
  for (int case_no = 0; cin >> dx >> dy >> n >> q, q; case_no++) {
    ll limit = max(dx, dy);
    ll sz = 2 * max(dx, dy);
    vector<vector<ll>> cnt(sz, vector<ll>(sz));
    vector<vector<ll>> pre(sz + 1, vector<ll>(sz + 1));
    while (n--) {
      ll x, y;
      cin >> x >> y, x--, y--;
      cnt[x - y + limit][x + y] = 1;
    }
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + cnt[i][j];
      }
    }
    cout << "Case " << case_no + 1 << ": \n";
    while (q--) {
      ll m;
      cin >> m;
      ll maxi = -1, rx = -1, ry = -1;
      for (ll y = 0; y < dy; y++) {
        for (ll x = 0; x < dx; x++) {
          ll xx = x - y + limit, yy = x + y;
          ll x0 = max(0ll, xx - m);
          ll y0 = max(0ll, yy - m);
          ll x1 = min(sz - 1, xx + m) + 1;
          ll y1 = min(sz - 1, yy + m) + 1;
          ll cur = pre[x1][y1] - pre[x0][y1] - pre[x1][y0] + pre[x0][y0];
          if (cur > maxi) {
            maxi = cur, rx = x, ry = y;
          }
        }
      }
      cout << maxi << " (" << rx + 1 << "," << ry + 1 << ")\n";
    }
  }
}
