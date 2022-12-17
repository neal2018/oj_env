#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    if (b < c) swap(b, c);
    ll diff = 1e18;
    auto calc = [&](ll x, ll y, ll z) { return a * x + b * y + c * z; };
    ll x = -1, y = -1, z = -1;
    auto update = [&](ll xx, ll yy, ll zz) {
      ll cur_diff = abs(3 * calc(xx, yy, zz) - (a + b + c) * n);
      if (cur_diff < diff) x = xx, y = yy, z = zz, diff = cur_diff;
    };
    for (ll i = 0; i <= n; i++) {
      ll l = 0, r = n - i;
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (3 * calc(i, mid, n - i - mid) <= (a + b + c) * n) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      update(i, l, n - i - l);
      if (n - i - l - 1 >= 0) update(i, l + 1, n - i - l - 1);
    }
    for (int i = 0; i < x; i++) cout << a << "\n";
    for (int i = 0; i < y; i++) cout << b << "\n";
    for (int i = 0; i < z; i++) cout << c << "\n";
    cout << endl;
    for (int i = 0, u, v; i < n; i++) cin >> u >> v;
  }
}
