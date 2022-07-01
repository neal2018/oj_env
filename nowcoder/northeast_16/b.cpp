#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
    deg[u]++, deg[v]++;
  }
  vector<int> q, nq;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) q.push_back(i);
  }
  vector<int> dist(n);
  int res = 0, need = n - k;
  for (; q.size() && need; swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      deg[node] = -1;
      if (dist[node] == 0) dist[node] = 1;
      res = max(res, dist[node]);
      if (--need == 0) break;
      for (auto& ne : g[node]) {
        if (deg[ne] <= 0) continue;
        dist[ne] = max(dist[ne], dist[node] + 1);
        if (--deg[ne] == 1) {
          nq.push_back(ne);
        }
      }
    }
  }
  cout << res << "\n";
}
