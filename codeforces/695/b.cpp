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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) cnt++;
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) cnt++;
    }
    auto check = [&](int x, int y, int z) {
      if (y > x && y > z) return 1;
      if (y < x && y < z) return 1;
      return 0;
    };
    int res = cnt;
    for (int i = 0; i < n; i++) {
      int t = cnt;
      if (i - 1 > 0) t -= check(a[i - 2], a[i - 1], a[i]);
      if (i > 0 && i < n - 1) t -= check(a[i - 1], a[i], a[i + 1]);
      if (i + 2 < n) t -= check(a[i], a[i + 1], a[i + 2]);
      int t2 = t;
      if (i > 0) {
        if (i - 1 > 0) t += check(a[i - 2], a[i - 1], a[i - 1]);
        if (i > 0 && i < n - 1) t += check(a[i - 1], a[i - 1], a[i + 1]);
        if (i + 2 < n) t += check(a[i - 1], a[i + 1], a[i + 2]);
      }
      if (i < n - 1) {
        if (i - 1 > 0) t2 += check(a[i - 2], a[i - 1], a[i + 1]);
        if (i > 0 && i < n - 1) t2 += check(a[i - 1], a[i + 1], a[i + 1]);
        if (i + 2 < n) t2 += check(a[i + 1], a[i + 1], a[i + 2]);
      }
      res = min({res, t, t2});
    }
    cout << res << "\n";
  }
}
