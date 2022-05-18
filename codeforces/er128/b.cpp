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
    ll left = -1;
    for (int i = 0; i < n && left == -1; i++) {
      for (int j = 0; j < m && left == -1; j++) {
        if (a[i][j] == 'R') {
          left = j;
          break;
        }
      }
    }
    ll f = 1;
    for (int i = 0; i < n && f; i++) {
      for (int j = 0; j < m && f; j++) {
        if (a[i][j] == 'R') {
          if (j < left) f = 0;
        }
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
