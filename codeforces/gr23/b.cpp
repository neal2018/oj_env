#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int i = 0, j = n - 1, res = 0;
    while (i < j) {
      while (i < n && a[i] == 0) i++;
      while (j >= 0 && a[j] == 1) j--;
      if (i < j) {
        res++, i++, j--;
      }
    }
    cout << res << "\n";
  }
}
