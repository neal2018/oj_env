#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b;
    cin >> a >> b;
    if (a > b) {
      cout << a - b << "\n";
      continue;
    }
    ll res = b - a;
    ll SQRT = ll(sqrt(b) + 2);
    for (int t = 1; t < SQRT; t++) {
      ll x = max((b + t - 1) / t - a, 0ll);
      ll cur = t * a + (t + 1) * x - b;
      res = min(res, cur);
    }
    for (int x = 0; x < SQRT; x++) {
      ll t = max((b + a + x - 1) / (a + x), 1ll);
      ll cur = t * a + (t + 1) * x - b;
      res = min(res, cur);
    }
    cout << res << "\n";
    // b = ta+tx-y
    // b = ta+(t+1)x-(x+y)
    // b = ta+t(x+y)-(t+1)y
    // y = ta+tx-b >= 0, x >= ceil(b/t) - a >= 0
    // y = ta+tx-b >= 0, t >= ceil(b/(a+x))
    // x+y = ta + (t+1)x - b >= x
    // ta + (t+1)(ceil(b/t) - a) - b
    // (t+1)ceil(b/t) - a - b
    // (t+1)((b+t-1)/t) - a - b
    //
    // b+t-1  >= a*t
  }
}
