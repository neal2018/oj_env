#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    ll g = 0;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    for (int i = 0, x; i < m; i++) {
      cin >> x;
      g = gcd(g, x);
    }
    vector<vector<ll>> b(g);
    for (int i = 0; i < n; i++) b[i % g].push_back(a[i]);
    ll even = 0, odd = 0;
    for (auto& v : b) {
      sort(v.begin(), v.end());
      ll all = accumulate(v.begin(), v.end(), 0ll);
      ll cur_even = all, cur_odd = -1e18;
      for (int i = 0; i < v.size(); i++) {
        all -= 2 * v[i];
        if (i % 2 == 0) {
          cur_odd = max(cur_odd, all);
        } else {
          cur_even = max(cur_even, all);
        }
      }
      odd += cur_odd, even += cur_even;
    }
    cout << max(odd, even) << "\n";
  }
}
