#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    ll res = 0;
    vector<ll> a(k);
    for (ll i = 0, x; i < n; i++) {
      cin >> x;
      res += x / k, a[x % k]++;
    }
    for (ll l = 1, r = k - 1; l <= r;) {
      while (a[r] == 0 && r > 0) r--;
      while ((a[l] == 0 || l + r < k) && l < k - 1) l++;
      if (l > r) break;
      ll minus = min(a[l], a[r]);
      if (l == r) {
        res += minus / 2;
        a[l] -= minus / 2 * 2;
        break;
      } else {
        res += minus;
        a[l] -= minus, a[r] -= minus;
      }
    }
    cout << res << "\n";
  }
}
