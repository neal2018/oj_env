#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr ld eps = 1e-8;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
  ll d, n, b;
  cin >> d >> n >> b;
  vector<array<ll, 2>> a(n);  // position, height
  for (auto& [p, h] : a) {
    cin >> p >> h;
  }
  ld res = 1e18;
  for (int times = 0; times <= b; times++) {
    ld A = ((ld)1.0 * d) / (times + 1);
    // cout << A << "\n";
    auto check = [&](ld mid) {
      ld sum = sqrt(mid * mid + A);
      ld minus = sqrt(mid * mid - A);
      ld vy = (sum + minus) / 2;
      ld vx = (sum - minus) / 2;
      // cout << mid << " " << vx << " " << vy << "\n";
      // cout << sum << " " << minus << "\n";
      for (auto [p, h] : a) {
        ld pp = p;
        while (pp > A) pp -= A;
        ld hh = -1.0 * pp * pp / (2 * vx * vx) + vy / vx * pp;
        // cout<<"hh = "<<hh<<"\n";
        if (hh <= h) return false;
      }
      return true;
    };
    ld l = sqrt(A), r = 1e9;
    while (r - l > eps) {
      ld mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
      // cout << mid << "\n";
    }
    res = min(res, r);
  }
  cout << res << "\n";
}