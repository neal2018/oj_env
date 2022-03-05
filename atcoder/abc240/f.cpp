#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<array<ll, 2>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    ll pre_a = 0, pre_b = 0, res = a[0][0];
    for (auto& [x, y] : a) {
      ll nex_b = pre_b + x * y;
      if (pre_b > 0 && nex_b < 0) {
        ll t = abs(pre_b / x);
        ll tmp = pre_a + (pre_b + x * t + pre_b + x) * t / 2;
        res = max(res, tmp);
      }
      pre_a = pre_a + (nex_b + pre_b + x) * y / 2;
      pre_b = nex_b;
      res = max(res, pre_a);
    }
    cout << res << "\n";
  }
}
