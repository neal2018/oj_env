#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    ll n, k;
    cin >> n >> k;
    if (k >= n - 1) {
      if (n == 4) {
        cout << -1 << "\n";
        continue;
      }
      vector<pair<ll, ll>> a;
      a.reserve(n / 2);
      for (ll i = 3; i < n / 2; i++) {
        a.push_back({i, n - i - 1});
      }
      for (auto& [x, y] : a) {
        int i = x, j = y;
        cout << i << " " << j << "\n";
      }
      cout << n - 2 << " " << n - 1 << "\n";
      cout << 0 << " " << 2 << "\n";
      cout << 1 << " " << n - 3 << "\n";
    } else {
      vector<pair<ll, ll>> a;
      a.reserve(n / 2);
      for (ll i = 1; i < n / 2; i++) {
        a.push_back({i, n - i - 1});
      }
      for (auto& [x, y] : a) {
        int i = x, j = y;
        if (x == k) {
          i = 0;
        } else if (y == k) {
          j = 0;
        }
        cout << i << " " << j << "\n";
      }
      cout << k << " " << n - 1 << "\n";
    }
  }
}