#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n, 1e18);
    vector<pair<ll, ll>> info(k);
    for (auto& [x, y] : info) cin >> x, x--;
    for (auto& [x, y] : info) cin >> y;
    for (auto& [p, t] : info) a[p] = min(a[p], t);
    for (ll i = 1; i < n; i++) a[i] = min(a[i], a[i - 1] + 1);
    for (ll i = n - 2; i >= 0; i--) a[i] = min(a[i], a[i + 1] + 1);
    for (auto& x : a) cout << x << " ";
    cout << "\n";
  }
}
