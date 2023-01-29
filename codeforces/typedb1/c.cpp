#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll dp0 = 0, dp1 = 0;
    auto cut = [&](int i) {
      if (i == 0) return array{0ll, a[0], 0ll, a[0]};
      if (i == n - 1) return array{a[i], 0ll, a[i], 0ll};
      ll x0 = 0, y0 = 0, x1 = 0, y1 = 0;
      if (a[i] >= 2 * s) {
        y0 = s, x0 = a[i] - y0;
      } else {
        x0 = min(s, a[i]), y0 = a[i] - x0;
      }
      if (a[i] >= 2 * s) {
        x1 = s, y1 = a[i] - x1;
      } else {
        y1 = min(s, a[i]), x1 = a[i] - y1;
      }
      return array{x0, y0, x1, y1};
    };
    for (int i = 1; i < n; i++) {
      auto [x0, y0, x1, y1] = cut(i);
      auto [x0p, y0p, x1p, y1p] = cut(i - 1);
      ll ndp0 = min(dp0 + y0p * x0, dp1 + y1p * x0);
      ll ndp1 = min(dp0 + y0p * x1, dp1 + y1p * x1);
      dp0 = ndp0, dp1 = ndp1;
    }
    cout << min(dp0, dp1) << "\n";
  }
}