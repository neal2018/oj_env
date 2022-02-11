#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<ll> dist(n, 1e17);
  dist[0] = 0;
  set<pair<ll, ll>> st{{0, 0}};
  while (st.size()) {
    auto [cost, node] = *st.begin();
    st.erase(st.begin());
    for (auto& ne : g[node]) {
      ll w = max(0ll, a[ne] - a[node]);
      if (cost + w < dist[ne]) {
        dist[ne] = cost + w;
        st.insert({cost + w, ne});
      }
    }
  }
  ll maxi = 0;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, a[0] - a[i] - dist[i]);
  }
  cout << maxi << "\n";
}
