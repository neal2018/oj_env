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
    sort(a.begin(), a.end());
    set<pair<ll, ll>> st;
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v;
      st.insert(minmax(u, v));
    }
    set<array<ll, 3>> poss;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] != a[j]) {
          auto [mini, maxi] = minmax(a[i], a[j]);
          poss.insert({-(cnt[a[i]] + cnt[a[j]]) * (a[i] + a[j]), mini, maxi});
        }
      }
    }
    while (poss.size()) {
      auto [val, i, j] = *poss.begin();
      if (st.count({i, j})) {
        poss.erase(poss.begin());
      } else {
        break;
      }
    }
    cout << -(*poss.begin())[0] << "\n";
  }
}
