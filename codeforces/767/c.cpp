#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    int res = 0;
    vector<int> c(n), cc(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        c[j] ^= 1;
        if (c[j]) res ^= a[i][j];
      }
      swap(cc, c);
      for (int j = 0; j < n; j++) {
        if (cc[j] && j > 0) c[j - 1] ^= 1;
        if (cc[j] && j < n - 1) c[j + 1] ^= 1;
      }
    }
    cout << res << "\n";
  }
}