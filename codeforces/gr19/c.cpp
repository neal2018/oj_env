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
    bool f = true;
    for (int i = 1; i < n - 1; i++) {
      if (a[i] != 1) f = false;
    }
    f = f || (n == 3 && a[1] % 2);
    if (f) {
      cout << -1 << "\n";
    } else {
      ll res = 0;
      for (int i = 1; i < n - 1; i++) res += (a[i] + 1) / 2;
      cout << res << "\n";
    }
  }
}
