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
    auto get = [&](ll n, ll m) {
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
      return a;
    };
    ll n, m, k;
    cin >> n >> m;
    auto a = get(n, m);
    cin >> k;
    auto b = get(k, m);
    cout << (a == b ? "Yes\n" : "No\n");
  }
}
