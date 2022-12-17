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
    auto g = a[0];
    for (auto& x : a) {
      g = gcd(x, g);
    }
    int res = 0;
    if (g != 1) {
      for (int i = n; i >= 1; i--) {
        if (gcd(i, g) == 1) {
          res = n - i + 1;
          break;
        }
      }
    }
    cout << min(res, 3) << "\n";
  }
}
