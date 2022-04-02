#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cout << fixed << setprecision(10);
  ll l, n, k;
  cin >> l >> n >> k;
  function<ld(ld, ld, ld)> f = [&](ld c, ld n, ld x) -> ld {
    ld r = n + c - c * ceil(n / c);
    if (n < x || n < 2) {
      return 0;
    } else if (x == 0) {
      return n;
    } else if ((2 * ceil(n / c) - 1) * x <= r) {
      return n - (2 * ceil(n / c) - 1) * x;
    } else {
      return f(c, n - r, x - r / ((2 * ceil(n / c) - 1)));
    }
  };
  cout << f(k, n, l) << "\n";
}