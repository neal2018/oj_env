#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll l, r;
    cin >> l >> r;
    ll n = r - l + 1;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll res = 0;
    for (int t = 17; t >= 0; t--) {
      sort(a.begin(), a.end());
      for (int i = 0; i < n; i++) {
        if ((a[i] >> t) != ((i + l) >> t)) {
          res |= 1ll << t;
          break;
        }
      }
      if (res & (1ll << t)) {
        for (auto& x : a) x ^= (1 << t);
      }
    }
    cout << res << "\n";
  }
}
