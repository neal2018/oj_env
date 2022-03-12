#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll l, r, a;
    cin >> l >> r >> a;
    // x - (a-1)*(x/a) = x%a + (x/a)
    ll res = max(r / a + r % a, l / a + l % a);
    ll sub = r / a * a - 1;
    if (sub >= l) res = max(res, sub / a + sub % a);
    cout << res << "\n";
  }
}
