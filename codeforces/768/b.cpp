#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> cnt(n);
    for (auto& x : a) cin >> x, x--, cnt[x]++;
    ll x, y, mini = 1e9, cur = 0;
    ll l = 0;
    for (ll r = 0; r < n; r++) {
      cur += cnt[r];
      while (cur - (n - cur) >= k) {
        ll len = r - l;
        if (mini > r - l) {
          x = l, y = r;
          mini = r - l;
        }
        cur -= cnt[l], l++;
      }
    }
    // cout << "\n";
    cout << x + 1 << " " << y + 1 << "\n";
    // cout << "\n";
    cur = 0;
    vector<pair<int, int>> res;
    res.reserve(n);
    int pre = 0;
    for (int i = 0; i < n; i++) {
      if (x <= a[i] && a[i] <= y) {
        cur++;
      } else {
        cur--;
      }
      if (i != n - 1 && cur > 0) {
        res.push_back({pre, i});
        cur = 0, pre = i + 1;
      }
    }
    res.push_back({pre, n - 1});
    while (res.size() > k) {
      auto [lx, ly] = res.back();
      res.pop_back();
      auto [llx, lly] = res.back();
      res.pop_back();
      res.push_back({llx, ly});
    }
    for (auto& [ii, jj] : res) cout << ii + 1 << " " << jj + 1 << "\n";
  }
}