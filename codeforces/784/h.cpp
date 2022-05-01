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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> v(31);
    for (auto& x : a) {
      for (ll t = 0; t < 31; t++) {
        if ((x & (1ll << t)) == 0) v[t]++;
      }
    }
    ll res = 0;
    for (int i = 30; i >= 0; i--) {
      if (k >= v[i]) {
        res |= (1ll << i), k -= v[i];
      }
    }
    cout << res << "\n";
  }
}
