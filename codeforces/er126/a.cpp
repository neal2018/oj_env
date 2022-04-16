#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) swap(a[i], b[i]);
      if (i > 0) {
        res += abs(a[i] - a[i - 1]);
        res += abs(b[i] - b[i - 1]);
      }
    }
    cout << res << "\n";
  }
}
