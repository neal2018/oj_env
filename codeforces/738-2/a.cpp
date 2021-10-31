#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll res = a[0];
    for (ll i = 1; i < n; i++) {
      res &= a[i];
    }
    cout << res << endl;
  }
  return 0;
}
