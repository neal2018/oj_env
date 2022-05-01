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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll res = 0, l = 0, r = n - 1, left = 0, right = 0;
    while (l <= r) {
      if (left <= right) {
        left += a[l++];
      } else {
        right += a[r--];
      }
      if (left == right) {
        res = max(res, l + (n - 1 - r));
      }
    }
    cout << res << "\n";
  }
}
