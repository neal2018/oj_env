#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int res = 0;
    for (int bit = 29; bit >= 0; bit--) {
      res |= (1 << bit);
      vector<int> c(n), d(n);
      for (int i = 0; i < n; i++) {
        c[i] = a[i] & res;
        d[i] = (~b[i]) & res;
      }
      sort(c.begin(), c.end());
      sort(d.begin(), d.end());
      if (c != d) res ^= (1 << bit);
    }
    cout << res << "\n";
  }
}
