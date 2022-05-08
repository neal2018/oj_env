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
    ll res = 0;
    for (int i = n - 2; i >= 0 && res != -1; i--) {
      if (a[i + 1] == 0) {
        res = -1;
        break;
      }
      while (a[i] >= a[i + 1]) {
        res++, a[i] /= 2;
      }
    }
    cout << res << "\n";
  }
}
