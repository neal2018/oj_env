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
    vector<array<ll, 2>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    int res = 0;
    for (int i = 0, j; i < n; i = j) {
      ll cur_gcd = a[i][0] * a[i][1], cur_lcm = a[i][1];
      for (j = i + 1; j < n; j++) {
        cur_gcd = gcd(cur_gcd, a[j][0] * a[j][1]);
        cur_lcm = lcm(cur_lcm, a[j][1]);
        if (cur_gcd % cur_lcm) break;
      }
      res++;
    }
    cout << res << "\n";
  }
}
