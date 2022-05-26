#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m;
  cin >> n >> m;
  vector<vector<array<int, 3>>> g(n);
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w, u--, v--;
    g[u].push_back({v, w, i}), g[v].push_back({u, w, i});
  }
  vector<int> from(n, -1);
  vector<ll> dist(n, 1e18);
  set<pair<ll, int>> st{{0, 0}};  // dist, node
  dist[0] = 0;
  while (st.size()) {
    auto [cur, node] = *st.begin();
    st.erase(st.begin());
    for (auto& [ne, cost, id] : g[node]) {
      if (cur + cost < dist[ne]) {
        dist[ne] = cur + cost;
        from[ne] = id;
        st.insert({dist[ne], ne});
      }
    }
  }
  for (int i = 1; i < n; i++) {
    cout << from[i] + 1 << " ";
  }
  cout << "\n";
}
