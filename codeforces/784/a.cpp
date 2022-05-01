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
    ll res = 0;
    if (n >= 1900) {
      res = 1;
    } else if (n >= 1600) {
      res = 2;
    } else if (n >= 1400) {
      res = 3;
    } else {
      res = 4;
    }
    cout << "Division " << res << "\n";
  }
}
