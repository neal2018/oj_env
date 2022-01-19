#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<vector<ll>> g(2 * n, vector<ll>(2 * n));
    for (auto& r : g) {
      for (auto& x : r) cin >> x;
    }
    ll cnt = 0;
    for (ll i = n; i < 2 * n; i++) {
      for (ll j = n; j < 2 * n; j++) {
        cnt += g[i][j];
      }
    }
    ll need = 1e18;
    for (auto [x, y] : vector<pair<ll, ll>>{{0, n},
                                            {0, 2 * n - 1},
                                            {n - 1, n},
                                            {n - 1, 2 * n - 1},
                                            {n, 0},
                                            {2 * n - 1, 0},
                                            {n, n - 1},
                                            {2 * n - 1, n - 1}}) {
      need = min(need, g[x][y]);
    }
    cout << cnt + need << "\n";
  }
}