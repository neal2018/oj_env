#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    int f = 0;
    ll l = 0, r = 0;
    for (; l < n; l++) {
      if (r <= l) r = l + 1;
      while (r < n && a[r] - a[l] < k) r++;
      if (r != n && a[r] - a[l] == k) {
        f = 1;
        break;
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
