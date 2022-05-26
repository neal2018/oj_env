#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto& x : a) cin >> x, x--;
  map<ll, vector<pair<ll, ll>>> mp;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    mp[u].push_back({v, i});
  }
  vector<ll> seen(n), res;
  for (int i = 0; i < n; i++) {
    if (seen[i]) continue;
    ll cur = i, cnt = 0;
    vector<ll> per;
    map<ll, ll> order;
    while (seen[cur] == 0) {
      per.push_back(cur);
      seen[cur] = 1;
      order[cur] = cnt++;
      cur = a[cur];
    }
    vector<array<ll, 3>> swp;
    for (auto u : per) {
      for (auto [v, id] : mp[u]) {
        ll x = u, y = v;
        if (order[x] > order[y]) swap(x, y);
        swp.push_back({x, y, id});
      }
    }
    sort(swp.begin(), swp.end());
    for (auto& [u, v, id] : swp) res.push_back(id);
  }
  vector<ll> ans(m);
  for (int i = 0; i < m; i++) {
    ans[res[i]] = i;
  }
  for (auto& x : ans) cout << x + 1 << " ";
  cout << "\n";
}
