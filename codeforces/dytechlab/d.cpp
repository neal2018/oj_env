#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0, u, v, w; i < m; i++) {
      cin >> u >> v >> w, u--, v--;
      g[u].push_back({v, w}), g[v].push_back({u, w});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, less<pair<ll, ll>>> pq;
    vector<ll> dist(n, inf);
    dist[0] = 0;
    pq.push({0, 0});
    while (pq.size()) {
      auto [cur, node] = pq.top();
      pq.pop();
      for (auto& [ne, w] : g[node]) {
        if (dist[ne] > cur + w) {
          dist[ne] = cur + w;
          pq.push({dist[ne], ne});
        }
        for (auto& [nne, _] : g[ne]) {
          if (dist[nne] > cur + 2 * w) {
            dist[nne] = cur + 2 * w;
            pq.push({dist[nne], nne});
          }
        }
      }
    }
    cout << dist[n - 1] << "\n";
  }
}
