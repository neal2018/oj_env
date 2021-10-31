#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n, q, l, r;
  cin >> T;
  string c;
  while (T--) {
    cin >> n >> q >> c;
    vector<ll> pref(n + 1);
    for (ll i = 0, sg = 1; i < n; i++, sg = -sg) {
      pref[i + 1] = pref[i] + sg * ((c[i] == '+') ? 1 : -1);
    }
    auto get = [&](ll x) { return (pref[x - 1] - pref[l - 1]) - (pref[r] - pref[x]); };
    auto go = [&](ll l, ll r) {
      ll l1 = l, r1 = r;
      while (r1 >= l1) {
        ll mid = (r1 + l1) / 2;
        if (get(mid) == 0) {
          return mid;
        } else if (get(l1) * get(mid) <= 0) {
          r1 = mid - 1;
        } else {
          l1 = mid + 1;
        }
      }
      return -1LL;
    };
    while (q--) {
      cin >> l >> r;
      ll diff = pref[r] - pref[l - 1];
      if (diff == 0) {
        cout << 0 << '\n';
      } else if (diff % 2 == 0) {
        cout << 2 << '\n' << l << " " << go(l + 1, r) << '\n';
      } else {
        cout << 1 << '\n' << go(l, r) << '\n';
      }
    }
  }
}