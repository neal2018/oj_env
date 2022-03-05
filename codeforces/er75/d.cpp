#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, s;
    cin >> n >> s;
    vector<pair<ll, ll>> a(n);
    vector<ll> lowest;
    lowest.reserve(n);
    for (auto& [x, y] : a) cin >> x >> y, lowest.push_back(x);
    sort(lowest.begin(), lowest.end());
    auto check = [&](ll mid) {
      // n/2 < mid, n/2 + 1 >=mid
      ll total = 0, left = 0, right = 0;
      vector<pair<ll, ll>> undecided;
      for (auto& [x, y] : a) {
        if (y < mid) {
          total += x, left++;
        } else if (x >= mid) {
          total += x, right++;
        } else {
          undecided.push_back({x, y});
        }
      }
      if (left > n / 2) return false;
      if (right > n / 2) return true;
      sort(undecided.begin(), undecided.end());
      for (int i = 0; i < n / 2 - left; i++) {
        total += undecided[i].first;
      }
      total += (ll(undecided.size()) - (n / 2 - left)) * mid;
      return total <= s;
    };
    ll l = lowest[n / 2], r = s;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << "\n";
  }
}
