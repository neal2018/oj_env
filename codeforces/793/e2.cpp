#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x, x--;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back({v, i}), g[v].push_back({u, i});
  }

  vector<int> seen(n), order(n), sz(n);
  for (int i = 0; i < n; i++) {
    if (seen[i]) continue;
    int cur = i, cnt = 0;
    while (seen[cur] == 0) {
      seen[cur] = 1;
      order[cur] = cnt++;
      cur = a[cur];
    }
    cur = i;
    do {
      sz[cur] = cnt, cur = a[cur];
    } while (cur != i);
  }
  vector<vector<int>> edges(m);
  vector<int> deg(m);
  for (int i = 0; i < n; i++) {
    int cnt = sz[i], pos = order[i];
    sort(g[i].begin(), g[i].end(), [&](const auto& x, const auto& y) {
      return (order[x.first] - pos + cnt) % cnt < (order[y.first] - pos + cnt) % cnt;
    });
    // clockwise order
    for (int j = 1; j < g[i].size(); j++) {
      edges[g[i][j - 1].second].push_back(g[i][j].second);
      deg[g[i][j].second]++;
    }
  }
  vector<int> q, nq;
  for (int i = 0; i < m; i++) {
    if (deg[i] == 0) q.push_back(i);
  }
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      cout << node + 1 << " ";
      for (auto& ne : edges[node]) {
        deg[ne]--;
        if (deg[ne] == 0) nq.push_back(ne);
      }
    }
  }
  cout << "\n";
}
