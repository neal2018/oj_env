#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> p(n);
  for (auto& [x, y] : p) cin >> x >> y;
  if (k == 1) {
    cout << "Infinity\n";
    return 0;
  }
  set<array<ll, 3>> lines;
  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto [x1, y1] = p[i];
      auto [x2, y2] = p[j];
      ll A = x2 - x1, B = y1 - y2, C = -x2 * y1 + x1 * y2;
      ll g = gcd(A, B);
      g = abs(gcd(g, C));
      if (g) {
        A /= g, B /= g, C /= g;
      }
      ll cnt = 0;
      for (int kk = 0; kk < n; kk++) {
        auto [x, y] = p[kk];
        if (A * y + B * x + C == 0) cnt++;
      }
      if (cnt >= k) {
        // cout << A << " " << B << " " << C << endl;
        if (lines.count({A, B, C}) == 0) {
          res++;
          lines.insert({A, B, C});
          lines.insert({-A, -B, -C});
        }
      }
    }
  }
  cout << res << "\n";
}
