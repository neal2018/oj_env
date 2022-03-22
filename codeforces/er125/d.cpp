#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, C, m;
  cin >> n >> C;
  vector<array<ll, 3>> a(n);
  vector<ll> mul(n);
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    auto& [c, d, h] = a[i];
    cin >> c >> d >> h;
    mul[i] = d * h;
    if (!mp.count(c) || mul[mp[c]] < mul[i]) mp[c] = i;
  }
  cin >> m;
  vector<ll> res(m, -1), maxi(C + 1, 0);
  vector<array<ll, 2>> qs(m);
  for (ll i = 0, d, h; i < m; i++) {
    cin >> d >> h;
    qs[i] = {d * h, i};
  }
  sort(qs.begin(), qs.end());
  for (auto& [c, i] : mp) {
    for (ll j = 1; j * c <= C; j++) {
      maxi[j * c] = max(maxi[j * c], mul[i] * j);
    }
  }
  ll cur = 0;
  for (ll i = 0; i <= C; i++) {
    while (cur < m && maxi[i] > qs[cur][0]) {
      res[qs[cur][1]] = i;
      cur++;
    }
  }
  for (auto& x : res) cout << x << " ";
}
