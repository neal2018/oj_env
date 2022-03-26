#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<array<ll, 3>> a(n + m);
  for (ll i = 0; i < n; i++) cin >> a[i][0];
  for (ll i = 0; i < n; i++) cin >> a[i][2];
  for (ll i = 0; i < n; i++) a[i][1] = -1;
  for (ll i = 0; i < m; i++) cin >> a[i + n][0];
  for (ll i = 0; i < m; i++) cin >> a[i + n][2];
  for (ll i = 0; i < m; i++) a[i + n][1] = 1;
  sort(a.begin(), a.end(), greater<array<ll, 3>>());
  multiset<ll> poss;
  for (auto [x, is_box, y] : a) {
    if (is_box == 1) {
      poss.insert(y);
    } else {
      auto it = poss.lower_bound(y);
      if (it == poss.end()) {
        cout << "No\n";
        return 0;
      }
      poss.erase(it);
    }
  }
  cout << "Yes\n";
}
