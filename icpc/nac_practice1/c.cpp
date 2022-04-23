#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int v;
  cin >> v;
  ll res = 1e18;
  auto calc = [&](ll a, ll b, ll c) {
    // cout<<a<<" "<<b<<" "<<c<<"\n";
    return 2 * (a * b + b * c + c * a);
  };
  for (ll i = 1; i * i <= v; i++) {
    if (v % i == 0) {
      for (ll j = 1; j * j <= i; j++) {
        if (i % j == 0) {
          // i, j, v/i/j
          res = min(res, calc(i / j, j, v / i));
          // res = min(res, calc(i, i / j, v / i));
        }
      }
      ll t = i;
      {
        ll i = v / t;
        // cout<<i<<"\n";
        for (ll j = 1; j * j <= i; j++) {
          if (i % j == 0) {
            // i, j, v/i/j
            res = min(res, calc(i / j, j, v / i));
            // res = min(res, calc(i, i / j, v / i));
          }
        }
      }
    }
  }
  cout << res << "\n";
}