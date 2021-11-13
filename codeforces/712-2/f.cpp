#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, res = 0, valid = 1, inf = 1e9;
  cin >> n;
  vector<int> f(n), color(n), mini(n), maxi(n);
  for (int i = 0, a, b; i < n; i++) {
    cin >> a >> b;
    a--, b--;
    if ((a < n) ^ (b < n)) {
      if (a > b) swap(a, b), color[a] = 1;
      f[a] = b;
    } else {
      valid = 0;
    }
  }
  if (!valid) return cout << -1 << '\n', 0;
  mini[0] = f[0];
  for (int i = 1; i < n; i++) mini[i] = min(mini[i - 1], f[i]);
  maxi[n - 1] = f[n - 1];
  for (int i = n - 2; i >= 0; i--) maxi[i] = max(maxi[i + 1], f[i]);
  for (int i = 0, pre = 0; i < n; i++) {
    if (i == n - 1 || mini[i] > maxi[i + 1]) {
      int mini1 = inf, mini2 = inf, cnt1 = 0, cnt2 = 0, total1 = 0, total2 = 0;
      for (int j = pre; j <= i; j++) {
        if (f[j] < mini1) {
          mini1 = f[j];
          cnt1 += color[j], total1++;
        } else if (f[j] < mini2) {
          mini2 = f[j];
          cnt2 += color[j], total2++;
        } else {
          return cout << -1 << '\n', 0;
        }
      }
      res += min(cnt1 + total2 - cnt2, cnt2 + total1 - cnt1);
      pre = i + 1;
    }
  }
  cout << res << '\n';
}