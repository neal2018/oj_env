#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(m), suf(m + 1);
  for (auto& x : a) cin >> x;
  for (int i = m - 1; i >= 0; i--) suf[i] = suf[i + 1] + a[i];
  vector<int> res(n + 2);
  for (int cur = 0, now = 0; cur <= n && now < m;) {
    if (cur + d - 1 + d - 1 + suf[now] >= n) {
      cur += (n - suf[now] - cur) / 2 + 1;
      cout << "YES\n";
      for (int i = now; i < m; i++) {
        for (int k = 0; k < a[i]; k++) {
          res[cur++] = i + 1;
        }
      }
      for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
      }
      cout << "\n";
      return 0;
    } else {
      for (int i = cur + d; i < cur + d + a[now]; i++) {
        res[i] = now + 1;
      }
      cur = cur + d + a[now] - 1;
      now++;
    }
  }
  cout << "NO\n";
}
