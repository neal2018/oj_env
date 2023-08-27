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
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int l = -2, r = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        if (l == -2) l = i;
        r = i;
      }
    }
    if (l == -2) {
      int i = 0;
      for (int j = 0; j < n; j++) {
        if (j > 0 && a[i] > a[j]) i = j;
        if (j - i > r - l) {
          l = i, r = j;
        }
      }
    } else {
      while (l > 0 && b[l - 1] <= b[l]) l--;
      while (r < n - 1 && b[r] <= b[r + 1]) r++;
    }
    cout << l + 1 << " " << r + 1 << "\n";
  }
}
