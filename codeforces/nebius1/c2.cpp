#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, x, p;
    cin >> n >> x >> p;
    x = (n - x) % n;
    // set<ll>
    [&] {
      for (ll i = 1; i <= min(p, 3 * n); i++) {
        ll val = ((i * (i + 1)) / 2 % n);
        if (val == x) {
          cout << "Yes\n";
          return;
        }
      }
      cout << "No\n";
    }();
  }
}
