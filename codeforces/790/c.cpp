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
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    ll res = 1e18;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ll cnt = 0;
        for (int k = 0; k < m; k++) {
          cnt += abs(a[i][k] - a[j][k]);
        }
        res = min(res, cnt);
      }
    }
    cout << res << "\n";
  }
}
