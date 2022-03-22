#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, b, x, y;
    cin >> n >> b >> x >> y;
    ll res = 0, pre = 0;
    for (int i = 1; i <= n; i++) {
      if (pre + x > b) {
        pre = pre - y;
      } else {
        pre = pre + x;
      }
      res += pre;
    }
    cout << res << "\n";
  }
}
