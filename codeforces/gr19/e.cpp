#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (auto& x : a) cin >> x, cnt[x]++;
    set<pair<ll, ll>> bad;
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v;
      bad.insert(minmax(u, v));
    }
    sort(a.begin(), a.end());
    map<ll, vector<ll>> occ;
    vector<ll> occ_v;
    for (auto& [k, v] : cnt) {
      occ[v].push_back(k);
      occ_v.push_back(v);
    }
    sort(occ_v.begin(), occ_v.end());
    occ_v.erase(unique(occ_v.begin(), occ_v.end()), occ_v.end());
    for (auto& [k, v] : occ) {
      sort(v.begin(), v.end(), greater<ll>());
    }
    ll cc = occ_v.size();
    ll res = 0;
    for (int i = 0; i < cc; i++) {
      for (int j = i; j < cc; j++) {
        auto& vl = occ[occ_v[i]];
        auto& vr = occ[occ_v[j]];
        ll nl = vl.size(), nr = vr.size();
        set<array<ll, 3>> poss{{-(vl[0] + vr[0]), 0, 0}};
        while (poss.size()) {
          auto [val, ii, jj] = *poss.begin();
          if (vl[ii] == vr[jj] || bad.count(minmax(vl[ii], vr[jj]))) {
            if (ii < nl - 1) poss.insert({-(vl[ii + 1] + vr[jj]), ii + 1, jj});
            if (jj < nr - 1) poss.insert({-(vl[ii] + vr[jj + 1]), ii, jj + 1});
            poss.erase(poss.begin());
          } else {
            res = max(res, (vl[ii] + vr[jj]) * (occ_v[i] + occ_v[j]));
            break;
          }
        }
      }
    }
    cout << res << "\n";
  };
}
