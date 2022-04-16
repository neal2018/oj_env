#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll q;
  cin >> q;
  vector<vector<array<ll, 3>>> qs(n + 1);
  for (int i = 0; i < q; i++) {
    ll l, r, x;
    cin >> l >> r >> x, l--;
    qs[l].push_back({x, -1, i});
    qs[r].push_back({x, 1, i});
  }
  vector<ll> res(q);
  map<ll, ll> mp;
  for (int i = 0; i <= n; i++) {
    for (auto& [val, is_end, id] : qs[i]) {
      res[id] += mp[val] * is_end;
    }
    if (i < n) mp[a[i]]++;
  }
  for (auto& x : res) cout << x << "\n";
}
