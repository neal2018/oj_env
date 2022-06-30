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
    int n, z, res = 0;
    cin >> n >> z;
    for (int x; [[maybe_unused]] auto i : views::iota(0, n)) {
      cin >> x;
      res = max(res, x | z);
    }
    cout << res << "\n";
  }
}
