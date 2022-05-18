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
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto& v : a) {
      for (auto& x : v) cin >> x;
    }
    vector<ll> left_down(n + m), right_down(n + m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        left_down[i + j] += a[i][j];
        right_down[i - j + m - 1] += a[i][j];
      }
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res = max(res, left_down[i + j] + right_down[i - j + m - 1] - a[i][j]);
      }
    }
    cout << res << "\n";
  }
}
