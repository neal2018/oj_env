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
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    cout << ([&] {
      for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          ll maxi = -1e18, sum = 0;
          for (int k = i; k <= j; k++) {
            maxi = max(maxi, a[k]);
            sum += a[k];
          }
          if (maxi < sum) return false;
        }
      }
      return true;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}