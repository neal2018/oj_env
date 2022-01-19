#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> k(n), h(n), res(n);
    for (auto& x : k) cin >> x;
    for (auto& x : h) cin >> x;
    ll maxi = 0;
    for (ll i = n - 1; i >= 0; i--) {
      res[i] = max(maxi, h[i]);
      if (i != 0) maxi = max(h[i], maxi) - (k[i] - k[i - 1]);
    }
    ll sum = 0;
    for (ll i = 1; i < n; i++) {
      ll diff = k[i] - k[i - 1];
      if (res[i] <= diff) {
        sum += (res[i] + 1) * res[i] / 2;
      } else {
        res[i] = diff + res[i - 1];
        sum += (res[i] + 1) * res[i] / 2;
        sum -= (res[i - 1] + 1) * res[i - 1] / 2;
      }
    }
    sum += (res[0] + 1) * res[0] / 2;
    cout << sum << "\n";
  }
}