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
    ll n, cnt = 0;
    cin >> n;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    ll res = n * n, OFFSET = n - 1;
    vector<int> nums(2 * n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        nums[i - j + OFFSET] += (a[i][j] == '1');
        cnt += (a[i][j] == '1');
      }
    }
    for (int ii = 0; ii < n; ii++) {
      ll t = nums[ii] + ((ii != n - 1) ? nums[n + ii] : 0);
      ll need = (n - t) + (cnt - t);
      res = min(res, need);
    }
    cout << res << "\n";
  }
}
