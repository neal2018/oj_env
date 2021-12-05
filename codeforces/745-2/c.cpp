#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    ll n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& x : g) cin >> x;
    vector col(n + 1, vector<ll>(m));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) col[j + 1][i] = col[j][i] + (g[j][i] == '0');
    ll res = 1e18, pre = 1e18;
    for (int i = 0; i < n; i++) {
      for (int j = i + 4; j < n; j++) {
        pre = 1e18;
        for (int k = 0; k < m; k++) {
          ll line_cost = col[j][k] - col[i + 1][k];
          if (k >= 3) res = min(res, line_cost + pre);
          if (k >= 2) {
            ll pre_line = col[j][k - 2] - col[i + 1][k - 2];
            for (ll t : {k, k - 1}) {
              ll add_on = (j - i - 1) - (col[j][t] - col[i + 1][t]);
              add_on += (g[j][t] == '0') + (g[i][t] == '0');
              pre_line += add_on;
            }
            pre += (j - i - 1) - line_cost;
            pre += (g[j][k] == '0') + (g[i][k] == '0');
            pre = min(pre, pre_line);
          }
        }
      }
    }
    cout << res << '\n';
  };
  for (; T--;) f();
}