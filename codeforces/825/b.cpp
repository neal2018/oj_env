#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

constexpr ld eps = 1e-7;

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
    int res = 0;
    for (int i = 1; i < n; i++) {
      int t = (a[i] + 2 * a[0] - 2) / (2 * a[0] - 1) - 1;
      res += t;
      // cout << t << "\n";
    }
    cout << res << "\n";
  }
}
