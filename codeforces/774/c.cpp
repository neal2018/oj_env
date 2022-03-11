#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<ll> fac{6,      24,      120,      720,       5040,       40320,
                 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200};
  ll sz = fac.size();
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    ll res = __builtin_popcountll(n);
    for (int i = (1 << sz) - 1; i >= 0; i--) {
      ll minus = 0, cnt = 0;
      for (int j = 0; j < sz; j++) {
        if ((i >> j) & 1) minus += fac[j], cnt++;
      }
      if (n - minus >= 0) res = min(res, cnt + __builtin_popcountll(n - minus));
    }
    cout << res << "\n";
  }
}
