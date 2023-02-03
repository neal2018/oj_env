#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<array<ll, 2>> cost;
    for (ll i = 0; i < n; i++) {
      cost.push_back({min(i + 1, n - i) + a[i], i});
    }
    vector<int> occ(n);
    sort(cost.begin(), cost.end());
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + cost[i][0];
      occ[cost[i][1]] = i;
    }
    ll res = 0;
    for (auto& [cur, id] : cost) {
      ll need = id + 1 + a[id];
      if (need > c) continue;
      ll l = 0, r = n;
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        ll total = pre[mid] + need;
        if (mid > occ[id]) {
          total -= cur;
        }
        if (total <= c) {
          l = mid;
          res = max(res, l + (mid <= occ[id]));
        } else {
          r = mid - 1;
        }
      }
      res = max(res, l + (l <= occ[id]));
    }
    cout << res << "\n";
  }
}
