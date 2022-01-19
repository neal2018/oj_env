#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, w;
  cin >> n >> w;
  vector<pair<ll, ll>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  sort(a.begin(), a.end(), [&](const pair<ll, ll>& x, const pair<ll, ll>& y) {
    return x.first * y.second > y.first * y.second;
  });
  ll res = 0, i = 0;
  while (w && i < n) {
    ll can = min(w, a[i].second);
    res += a[i].first * can;
    w -= can, i++;
  }
  cout<<res << "\n";
}