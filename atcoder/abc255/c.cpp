#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll x, a, d, n;
  cin >> x >> a >> d >> n;
  // t = a + i * d, 0<=i<=n-1
  if (d < 0) {
    d = -d, a = a - (n - 1) * d;
  }
  if (x <= a) {
    cout << (a - x) << "\n";
    return 0;
  }
  if (x >= a + (n - 1) * d) {
    cout << (x - (a + (n - 1) * d)) << "\n";
    return 0;
  }
  ll res = 1e18;
  {
    // a + i*d >= x
    // i*d >= (x - a)
    ll i = (x - a + d - 1) / d;
    res = min(res, abs(x - (a + i * d)));
  }
  {
    // a + i*d <= x
    // i*d <= (x - a)
    ll i = (x - a) / d;
    res = min(res, abs(x - (a + i * d)));
  }
  cout << res << "\n";
}
