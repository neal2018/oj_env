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
    ll f = 0;
    for (auto start : {a[0] - 1, a[0], a[0] + 1}) {
      ll can = 1;
      for (int i = 0; i < n; i++, start++) {
        if (a[i] - 1 != start && a[i] != start && a[i] + 1 != start) {
          can = 0;
          break;
        }
      }
      f |= can;
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
