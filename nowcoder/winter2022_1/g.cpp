#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<pair<ll, ll>> interval;  // pos, end:-1, start:1, [l, r)
    interval.reserve(n);
    auto add = [&](ll l, ll r) {
      interval.push_back({l, 1});
      interval.push_back({r, -1});
    };
    for (int i = 1; i < n - 1; i++) {
      auto x = a[i], left = a[i - 1], right = a[i + 1];
      ll mini = min(left, right), maxi = max(left, right);
      if (x == left || x == right) {
        add(-inf, inf);
      } else if (left > x && right > x) {
        add((mini + x + 1) / 2, inf);
      } else if (left < x && right < x) {
        add(-inf, (maxi + x) / 2 + 1);
      } else {
        add(-inf, (mini + x) / 2 + 1);
        add((maxi + x + 1) / 2, inf);
      }
    }
    sort(interval.begin(), interval.end());
    ll res = 0, cur = 0, sz = interval.size();
    for (int i = 0, j; i < sz; i = j) {
      j = i;
      while (j < sz && interval[i].first == interval[j].first) j++;
      for (int k = i; k < j; k++) {
        auto& [pos, f] = interval[k];
        cur += (f == 1 ? 1 : -1);
      }
      res = max(res, cur);
    }
    cout << n - 2 - res << "\n";
  }
}