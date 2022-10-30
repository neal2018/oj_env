#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    pair<ll, ll> even{}, odd{};
    for (ll i = 0, x; i < n; i++) {
      cin >> x;
      if (x & 1) {
        odd.first += x, odd.second += 1;
      } else {
        even.first += x, even.second += 1;
      }
    }
    while (q--) {
      ll t, x;
      cin >> t >> x;
      if (t == 0) {
        even.first += even.second * x;
        if (x & 1) {
          odd.first += even.first;
          odd.second += even.second;
          even = {};
        }
      } else {
        odd.first += odd.second * x;
        if (x & 1) {
          even.first += odd.first;
          even.second += odd.second;
          odd = {};
        }
      }
      cout << (odd.first + even.first) << "\n";
    }
  }
}
