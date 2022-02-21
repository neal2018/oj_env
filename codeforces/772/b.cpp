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
    ll res = 0;
    for (auto& x : a) cin >> x;
    for (int i = 1; i < n - 1; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        res++, a[i + 1] = a[i];
        if (i < n - 2) {
          a[i + 1] = max(a[i + 1], a[i + 2]);
        }
      }
    }
    cout << res << "\n";
    for (auto& x : a) cout << x << " ";
    cout << "\n";
  }
}
