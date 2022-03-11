#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    ll res = 1e18;
    res = min(res, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
    res = min(res, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
    auto aa = a, bb = b;
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    vector<ll> cost(4, 1e18);
    {
      auto it = lower_bound(bb.begin(), bb.end(), a[0]);
      if (it != bb.end()) cost[0] = min(cost[0], abs(a[0] - *it));
      if (it != bb.begin()) cost[0] = min(cost[0], abs(a[0] - *(--it)));
    }
    {
      auto it = lower_bound(bb.begin(), bb.end(), a[n - 1]);
      if (it != bb.end()) cost[1] = min(cost[1], abs(a[n - 1] - *it));
      if (it != bb.begin()) cost[1] = min(cost[1], abs(a[n - 1] - *(--it)));
    }
    swap(a, b);
    swap(aa, bb);
    {
      auto it = lower_bound(bb.begin(), bb.end(), a[0]);
      if (it != bb.end()) cost[2] = min(cost[2], abs(a[0] - *it));
      if (it != bb.begin()) cost[2] = min(cost[2], abs(a[0] - *(--it)));
    }
    {
      auto it = lower_bound(bb.begin(), bb.end(), a[n - 1]);
      if (it != bb.end()) cost[3] = min(cost[3], abs(a[n - 1] - *it));
      if (it != bb.begin()) cost[3] = min(cost[3], abs(a[n - 1] - *(--it)));
    }
    swap(a, b);
    swap(aa, bb);
    res = min(res, accumulate(cost.begin(), cost.end(), 0ll));
    res = min(res, abs(a[0] - b[0]) + cost[1] + cost[3]);
    res = min(res, abs(a[0] - b[n - 1]) + cost[1] + cost[2]);

    res = min(res, abs(a[n - 1] - b[0]) + cost[0] + cost[3]);
    res = min(res, abs(a[n - 1] - b[n - 1]) + cost[0] + cost[2]);

    cout << res << "\n";
  };
}
