#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    [&] {
      for (ll y = b + 1; y <= d; y++) {
        ll need = lcm(y, a * b) / y;
        ll x = c / need * need;
        if (x > a) {
          cout << x << " " << y << "\n";
          return;
        }
      }
      cout << "-1 -1\n";
    }();
  }
}
