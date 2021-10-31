#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    ll x = 0, y = 0;
    bool f = true;
    for (ll mul = 1; n > 0; f = !f, n /= 10) {
      if (f) {
        x += n % 10 * mul;
      } else {
        y += n % 10 * mul;
        mul *= 10;
      }
    }
    cout << (x + 1) * (y + 1) - 2 << '\n';
  }
}