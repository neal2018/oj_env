#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> row(n), col(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        row[i] += (a[i][j] == '*');
        col[j] += (a[i][j] == '*');
      }
    }
    ll res = 1e18;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ll cur = n - row[i] + m - col[j];
        if (a[i][j] == '.') cur--;
        res = min(res, cur);
      }
    }
    cout << res << "\n";
  }
}
