#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(k);
  for (auto& x : a) cin >> x, x--;
  vector<pair<ll, ll>> people(n);
  for (auto& [x, y] : people) cin >> x >> y;
  ll maxi = 0;
  for (auto& [x, y] : people) {
    ll dist = 1e18;
    for (auto& i : a) {
      ll cur = (x - people[i].first) * (x - people[i].first) +
               (y - people[i].second) * (y - people[i].second);
      dist = min(dist, cur);
    }
    maxi = max(maxi, dist);
  }
  cout << sqrt(maxi) << "\n";
}
