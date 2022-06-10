#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    ll maxi = -2e9;
    for (int i = 0; i < n; i++) {
      maxi = max(maxi, a[i] - b[i]);
    }
    if (maxi < 0) {
      cout << "NO\n";
      continue;
    }
    for (auto& x : a) {
      x -= maxi;
      x = max(0ll, x);
    }
    cout << ((a == b) ? "YES\n" : "NO\n");
  }
}
