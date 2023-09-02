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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> pre(n, 1), suf(n, 1);
    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) {
        pre[i] = pre[i - 1];
      } else {
        pre[i] = pre[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] < a[i + 1]) {
        suf[i] = suf[i + 1];
      } else {
        suf[i] = suf[i + 1] + 1;
      }
    }
    int res = n;
    for (int i = -1; i < n; i++) {
      // [0, i][i+1, n]
      auto left = i >= 0 ? pre[i] : 0;
      auto right = i < n - 1 ? suf[i + 1] : 0;
      res = min(res, left + max(right - 1, 0));
    }
    cout << res << "\n";
  }
}
