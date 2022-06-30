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
    vector<pair<ll, ll>> a;
    for (ll i = 0, x; i < n; i++) {
      cin >> x;
      ll p = 1;
      while (x % m == 0) p *= m, x /= m;
      if (a.size() && a.back().second == x) {
        a.back().first += p;
      } else {
        a.push_back({p, x});
      }
    }
    ll k;
    cin >> k;
    vector<ll> b(k);
    for (auto& x : b) cin >> x;
    n = a.size();
    cout << ([&] {
      int i = 0, j = 0;
      auto go = [&](ll x) {
        a[i].first -= x;
        if (a[i].first == 0) i++;
      };
      for (; j < k && i < n;) {
        if (a[i].second == b[j]) {
          go(1), j++;
        } else {
          ll p = 1;
          while (b[j] % m == 0) p *= m, b[j] /= m;
          if (b[j] != a[i].second) return false;
          if (a[i].first < p) return false;
          go(p), j++;
        }
      }
      return j == k && i == n;
    }()
                 ? "Yes\n"
                 : "No\n");
  }
}
