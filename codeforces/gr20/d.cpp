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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& x : a) cin >> x, x--;
    for (auto& x : b) cin >> x, x--;
    vector<ll> mark(n);
    vector<vector<ll>> pos(n);
    for (int i = 0; i < n; i++) {
      pos[a[i]].push_back(i);
    }
    ll i = n - 1;
    ll f = 1;
    for (ll j = n - 1, k; j >= 0 && f; j = k) {
      for (k = j; k >= 0 && b[k] == b[j];) k--;
      while (i >= 0 && a[i] != b[j]) {
        if (mark[i] == 0) {
          f = 0;
          break;
        }
        i--;
      }
      if (i < 0) {
        f = 0;
        break;
      }
      if (mark[i]) {
        if (pos[b[j]].size() == 0) {
          f = 0;
          break;
        }
        mark[pos[b[j]].back()] = 1;
        pos[b[j]].pop_back();
        pos[b[j]].push_back(i);
      }
      for (ll ii = j; ii > k; ii--) {
        if (pos[b[j]].size() == 0) {
          f = 0;
          break;
        }
        mark[pos[b[j]].back()] = 1;
        pos[b[j]].pop_back();
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
