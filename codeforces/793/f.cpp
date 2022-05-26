#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), pre(n, n), nex(n, -1);
    map<ll, vector<ll>> mp;
    for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]].push_back(i);
    for (ll i = 0, l, r; i < m; i++) {
      cin >> l >> r, l--, r--;
      pre[r] = min(pre[r], l), nex[l] = max(nex[l], r);
    }
    for (ll i = 1; i < n; i++) nex[i] = max(nex[i], nex[i - 1]);
    for (ll i = n - 2; i >= 0; i--) pre[i] = min(pre[i], pre[i + 1]);
    vector<vector<ll>> event(n + 1);
    ll maxi = n;
    multiset<ll> need;
    auto insert = [&](ll l, ll r) {
      maxi = min(maxi, r);
      need.insert(l);
      event[l + 1].push_back(r);
    };
    for (int i = 0; i < n; i++) {
      if (pre[i] < i) {
        auto it = lower_bound(mp[a[i]].begin(), mp[a[i]].end(), pre[i]);
        if (*it < i) insert(*it, i);
      }
      if (nex[i] > i) {
        auto it = upper_bound(mp[a[i]].begin(), mp[a[i]].end(), nex[i]) - 1;
        if (*it > i) insert(i, *it);
      }
    }
    if (need.empty()) {
      cout << "0\n";
      continue;
    }
    ll res = n;
    for (int i = 0; i <= maxi; i++) {
      for (auto& r : event[i]) {
        need.erase(need.find(i - 1));
        need.insert(r);
      }
      res = min(res, *need.rbegin() - i + 1);
    }
    cout << res << "\n";
  }
}
