#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
int main() {
  ll n, M;
  cin >> n >> M;
  vector<pair<ll, ll>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  auto check = [&](i128 mid) {
    i128 res = 0;
    for (auto& [p, cost] : a) {
      if (p * mid - cost >= 0) {
        res += p * mid - cost;
      }
    }
    return res >= M;
  };
  i128 l = 0, r = 1e18;
  while (l < r) {
    i128 mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << (ll)l << "\n";
}