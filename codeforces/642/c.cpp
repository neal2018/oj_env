#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    ll res = (n + 1) / 2 * n * n;
    for (ll i = n; i > 0; i -= 2) {
      res -= i * i;
    }
    cout << res << "\n";
  }
}
