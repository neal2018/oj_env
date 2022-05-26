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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll res = 0;
    ll maxi = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] < maxi) {
        res++;
        maxi = -1;
      } else {
        maxi = max(maxi, a[i]);
      }
    }
    cout << res << "\n";
  }
}
