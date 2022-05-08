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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m), id(n);
    for (auto& x : a) cin >> x, x--;
    for (auto& x : b) cin >> x, x--;
    for (int i = 0; i < n; i++) {
      id[a[i]] = i;
    }
    ll res = 0, last = -1, moved = 0;
    for (auto& x : b) {
      auto pos = id[x];
      if (pos <= last) {
        res++;
      } else {
        res += 2 * (pos - moved) + 1;
        last = pos;
      }
      moved++;
    }
    cout << res << "\n";
  }
}
