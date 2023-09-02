#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, d, p;
  cin >> n >> d >> p;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.rbegin(), a.rend());
  ll i = 0;
  ll res = 0;
  while (i < n) {
    ll cur = 0;
    for (ll j = i; j < min(i + d, n); j++) cur += a[j];
    if (cur > p) {
      res += p, i = min(i + d, n);
    } else {
      break;
    }
  }
  res += accumulate(a.begin() + i, a.end(), 0ll);
  cout << res << "\n";
}
