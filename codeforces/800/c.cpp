#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<ll> dist(n, inf), deg(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[v].push_back(u), deg[u]++;
  }
  set<pair<ll, ll>> st;
  dist[n - 1] = 0, st.insert({0, n - 1});
  while (st.size()) {
    auto [cost, node] = *st.begin();
    st.erase(st.begin());
    if (cost > dist[node]) continue;
    for (auto& ne : g[node]) {
      deg[ne]--;
      ll ne_cost = cost + deg[ne] + 1;
      if (ne_cost < dist[ne]) {
        dist[ne] = ne_cost, st.insert({ne_cost, ne});
      }
    }
  }
  cout << dist[0] << "\n";
}
