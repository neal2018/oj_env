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
    if (n % 2 == 0) {
      iota(a.begin(), a.end(), 2);
      a[n - 3] = 1, a[n - 2] = n - 1, a[n - 1] = n;
      reverse(a.begin(), a.begin() + n - 3);
    } else {
      iota(a.begin(), a.end(), 1);
      if (a.size() > 5) {
        reverse(a.begin() + 3, a.begin() + n - 2);
      }
    }
    for (auto& x : a) cout << x << ' ';
    cout << "\n";
    // int res = 0;
    // for (auto& x : a) {
    //   if (res < x) {
    //     res += x;
    //   } else {
    //     res = 0;
    //   }
    // }
    // cout << res << "\n";
  }
}
