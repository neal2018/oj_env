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
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (x > a) {
      c -= (x - a);
    }
    cout << (c >= 0 && 
    b + c >= y ? "YES\n" : "NO\n");
  }
}
