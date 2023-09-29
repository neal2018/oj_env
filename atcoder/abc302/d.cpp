#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, d;
  cin >> n >> m >> d;
  vector<ll> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll res = -1;
  for (auto& x : a) {
    auto it = upper_bound(b.begin(), b.end(), x + d);
    if (it == b.begin()) continue;
    it--;
    auto y = *it;
    if (!(x - d <= y && y <= x + d)) continue;
    res = max(res, x + y);
  }
  cout << res << "\n";
}
