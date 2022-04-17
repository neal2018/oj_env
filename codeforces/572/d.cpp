#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto ask = [&](ll l, ll r) {
    // x+l, r
    cout << "? " << l + r << " " << l << endl;
    ll res = 0;
    cin >> res;
    return res;
  };
  int T;
  cin >> T;
  while (T--) {
    ll addon = 1;
    for (ll t = 0; t < 30; t++) {
      ll ans = ask(addon, 1ll << (t + 1));
      if ((ans & (1ll << (t + 1))) != (1ll << (t + 1))) {
        addon += (1ll << t);
      }
    }
    cout << "! " << (1ll << (30)) - addon << endl;
  }
}
