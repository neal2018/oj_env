#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, l, r;
    cin >> n >> l >> r;
    [&] {
      vector<ll> res(n);
      for (ll i = n; i >= 1; i--) {
        auto t = r % i;
        if (r - t >= l) {
          res[i - 1] = r - t;
        } else {
          cout << "NO\n";
          return;
        }
      }
      cout << "YES\n";
      for (auto& x : res) cout << x << " ";
      cout << "\n";
    }();
  }
}
