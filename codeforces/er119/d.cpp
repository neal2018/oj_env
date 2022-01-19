#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ranges::sort(a);
    ll res = 1e18;
    for (ll c1 = 0; c1 < 5; c1++) {
      for (ll c2 = 0; c2 < 5; c2++) {
        ll c3 = 0;
        for (auto x : a) {
          ll need = 1e18;
          for (ll cc1 = 0; cc1 <= c1; cc1++) {
            for (ll cc2 = 0; cc2 <= c2; cc2++) {
              if (cc1 + 2 * cc2 <= x && (x - cc1 - 2 * cc2) % 3 == 0) {
                need = min(need, (x - cc1 - 2 * cc2) / 3);
              }
            }
          }
          c3 = max(c3, need);
        }
        res = min(res, c1 + c2 + c3);
      }
    }
    cout << res << '\n';
  }
}