#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, m;
  cin >> T;
  while (T--) {
    cin >> m >> n;
    vector g(m, vector<int>(n));
    for (auto& r : g)
      for (auto& x : r) cin >> x;
    auto check = [&](ll mid) {
      vector<int> f(n, 0);
      int two = 0;
      for (auto& r : g) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          if (r[i] >= mid) f[i] = 1, cnt++;
        }
        if (cnt > 1) two = 1;
      }
      return accumulate(f.begin(), f.end(), 0) == n && two;
    };
    ll l = 0, r = 1e9;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << '\n';
  }
}