#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, l, r;
  cin >> n >> l >> r;
  ll res = 0;
  for (ll i = 0, p = 1; p <= n; i++, p *= 2) {
    if (n & p) {
      ll maxi = 2 * p - 1, mini = p;
      maxi = min(maxi, r), mini = max(mini, l);
      res += max(0ll, maxi - mini + 1);
    }
  }
  cout << res << '\n';
}