#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    vector a(2, vector<ll>(m));
    for (auto& r : a) {
      for (auto& x : r) cin >> x, x++;
    }
    a[0][0] = 0;
    vector minu(2, vector<ll>(m + 1, -1e18));
    vector plus(2, vector<ll>(m + 1, -1e18));
    for (int i = m - 1; i >= 0; i--) {
      for (int j : {0, 1}) {
        minu[j][i] = max(minu[j][i + 1], a[j][i] - i);
        plus[j][i] = max(plus[j][i + 1], a[j][i] + i);
      }
    }
    ll start = -1, remain = 2 * m - 1;
    ll res = 1e18;
    for (int i = 0; i < m; i++) {
      auto f0 = [&](int t) {
        start = max(start + 1, a[0][i]);
        ll up = minu[0][i] + remain + i, down = plus[1][i + t] - (i + t);
        res = min(res, max({start + remain, up, down}));
        remain--;
      };
      auto f1 = [&](int t) {
        start = max(start + 1, a[1][i]);
        ll up = minu[1][i] + remain + i, down = plus[0][i + t] - (i + t);
        res = min(res, max({start + remain, up, down}));
        remain--;
      };
      if (i % 2 == 0) {
        f0(0), f1(1);
      } else {
        f1(0), f0(1);
      }
    }
    cout << res << "\n";
  }
}
