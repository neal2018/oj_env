#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto f = [&]() {
    ll hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    for (int i = 0; i <= k; i++) {
      ll new_hc = hc + a * i;
      ll new_dc = dc + w * (k - i);
      if ((new_hc + dm - 1) / dm >= (hm + new_dc - 1) / new_dc) {
        return true;
      }
    }
    return false;
  };
  while (T--) cout << (f() ? "YES\n" : "NO\n");
}