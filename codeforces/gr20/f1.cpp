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
    vector<ll> a(n);
    for (auto& x : a) cin >> x, x--;
    vector<vector<ll>> pos(n);
    for (int i = 0; i < n; i++) pos[a[i]].push_back(i);
    ll maxi = 0;
    vector<ll> p, inv(n), b(n);
    for (auto& v : pos) {
      maxi = max(maxi, (ll)v.size());
      for (auto& x : v) p.push_back(x);
    }
    for (int i = 0; i < n; i++) inv[p[i]] = i;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) b[i] = a[(inv[i] + maxi) % n];
    for (auto& x : b) cout << x + 1 << " ";
    cout << "\n";
  }
}
