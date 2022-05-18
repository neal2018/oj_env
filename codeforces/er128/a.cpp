#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if ((l2 <= l1 && l1 <= r2) || (l1 <= l2 && l2 <= r1)) {
      cout << max(l1, l2) << "\n";
    } else {
      cout << l1 + l2 << "\n";
    }
  }
}
