#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), h(n);
    for (auto& x : a) cin >> x;
    for (auto& x : h) cin >> x;
    ll res = 0, cur_fruit = 0;
    for (ll i = 0, j = 0; i < n; i++) {
      if (i == 0 || h[i] != h[i - 1]) {
        j = i, cur_fruit = 0;
      }
      j = max(i, j);
      while (j < n && (j == i || h[j - 1] % h[j] == 0) && cur_fruit + a[j] <= k) {
        cur_fruit += a[j], j++;
      }
      res = max(res, j - i);
      if (j > i) cur_fruit -= a[i];
    }
    cout << res << "\n";
  }
}
