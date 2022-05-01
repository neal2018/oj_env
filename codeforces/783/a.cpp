#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll res = 1e18;
  for (int i = 0; i < n; i++) {
    ll cur = 0;
    for (ll j = i - 1, pre = 0; j >= 0; j--) {
      ll need = (pre + a[j]) / a[j];
      pre = need * a[j];
      cur += need;
    }
    for (ll j = i + 1, pre = 0; j < n; j++) {
      ll need = (pre + a[j]) / a[j];
      pre = need * a[j];
      cur += need;
    }
    res = min(res, cur);
  }
  cout << res << "\n";
}
