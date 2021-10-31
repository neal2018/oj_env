#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, m, x;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<ll> a(n), pre(n + 1);
    unordered_map<ll, ll> mp = {{0, 0}};
    unordered_map<ll, vector<pair<ll, ll>>> mods;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pre[i + 1] = a[i] + pre[i];
    }
    bool revserse = (pre[n] < 0);
    if (pre[n] < 0)
      for (int i = 0; i < n; i++) pre[i + 1] = -pre[i + 1], a[i] = -a[i];
    for (int i = 0; i < n; i++)
      if (mp.count(pre[i + 1]) == 0) mp[pre[i + 1]] = i + 1;
    if (pre[n] != 0) {
      for (int i = 0; i < n; i++) {
        ll y = pre[i + 1] % pre[n];
        if (y < 0) y += pre[n];
        mods[y].push_back({pre[i + 1], i + 1});
      }
      mods[0].push_back({0, 0});
      for (auto t = mods.begin(); t != mods.end(); t++) {
        sort(t->second.begin(), t->second.end());
      }
    }
    while (m--) {
      cin >> x;
      if (revserse) x = -x;
      if (mp.count(x)) {
        cout << mp[x] << '\n';
        continue;
      }
      if (pre[n] != 0) {
        ll y = x % pre[n];
        if (y < 0) y += pre[n];
        auto t = lower_bound(mods[y].begin(), mods[y].end(), pair<ll, ll>{x, 0ll});
        if (t == mods[y].begin()) {
          cout << -1 << '\n';
        } else {
          --t;
          auto tt = lower_bound(mods[y].begin(), mods[y].end(), pair<ll, ll>{t->first, 0ll});
          cout << n * (x - tt->first) / pre[n] + tt->second << '\n';
        }
      } else {
        cout << -1 << '\n';
      }
    }
  }
}