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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = n - k; i < n; i++) {
      cin >> a[i];
    }
    for (ll i = n - 1; i > n - k; i--) {
      a[i] -= a[i - 1];
    }
    if (k == 1) {
      cout << "Yes\n";
      continue;
    }
    if (!is_sorted(a.begin() + n - k + 1, a.end())) {
      cout << "No\n";
      continue;
    }
    if (a[n - k + 1] * (n - k + 1) >= a[n - k]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
