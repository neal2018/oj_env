#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int T;
  cin >> T;
  for (int n; T--;) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ll cnt = 0;
    for (ll l = 0, r; l < n; l = r) {
      // c >= 2b - a
      for (r = l; r < n && a[r] == a[l];) r++;
      ll cur = r - l, j = r;
      while (j < n) {
        cur++;
        j = ranges::lower_bound(a, 2 * a[j] - a[l]) - a.begin();
      }
      cnt = max(cnt, cur);
    }
    cout << n - cnt << '\n';
  }
}