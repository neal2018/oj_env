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
    ll n, m;
    cin >> n >> m;
    ll total = 0, neg = 0, zero = 0, mini = 1e18;
    for (ll i = 0, x; i < n * m; i++) {
      cin >> x;
      if (x < 0) neg = !neg;
      if (x == 0) zero = 1;
      x = abs(x);
      mini = min(mini, x);
      total += x;
    }
    if (!neg || zero) {
      cout << total << "\n";
    } else {
      cout << total - 2 * mini << "\n";
    }
  }
}
