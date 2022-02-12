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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        // [i, j]
        ll cur = 0;
        for (int k = i; k <= j; k++) {
          cur++;
          if (a[k] == 0) cur++;
        }
        res += cur;
      }
    }
    cout << res << "\n";
  }
}
