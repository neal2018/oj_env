#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
using pii = pair<int,int>;

const int INF = 2e9 + 69;

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<pair<int,int>>> adj(2*n);
  vector<vector<pair<int,int>>> adj_inv(2*n);
  vector<int> indegree(2*n);
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[v].push_back({u + n, w});
    adj[v + n].push_back({u, w});
    adj_inv[u + n].push_back({v, w});
    adj_inv[u].push_back({v + n, w});
    indegree[u + n]++; indegree[u]++;
  }

  priority_queue<pii,vector<pii>,greater<pii>> pq;
  vector<int> dist(2*n);
  for(int i = 0; i < 2*n; i++) dist[i] = INF;
  dist[t] = 0, dist[t + n] = 0;
  pq.push({0, t}); pq.push({0, t + n});
  while(!pq.empty()) {
    auto [cur_dist, cur] = pq.top();
    pq.pop();
    if(cur_dist > dist[cur]) continue;
    for(auto [v, w] : adj[cur]) {
      indegree[v]--;
      if(v >= n) assert(indegree[v] >= 0);
      if(v < n) {
        int cand = cur_dist + w;
        if(cand < dist[v]) {
          dist[v] = cand;
          pq.push({cand, v});
        }
      }
      else if(indegree[v] == 0) {
        int cand = 0;
        for(auto [v2, w2] : adj_inv[v]) {
          // assert(dist[v2] != INF);
          // assert(v2 < n);
          cand = max(cand, w2 + dist[v2]);
        }
        dist[v] = cand;
        pq.push({cand, v});
      }
    }
  }

  if(dist[s + n] == INF) cout << "infinity\n";
  else cout << dist[s + n] << '\n';
}