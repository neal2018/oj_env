#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    ll res = 1e18;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        ll p, q, d = 1;
        if (a[i] == a[j]) {
          p = a[i], q = 0;
        } else {
          p = j * a[i] - i * a[j], q = a[j] - a[i], d = j - i;
        }
        ll cnt = 0;
        for (int k = 0; k < n; k++) {
          if (d * a[k] != p + q * k) {
            cnt++;
          }
        }
        res = min(res, cnt);
      }
    }
    cout << res << "\n";
  }
}