#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  for (auto& r : a) {
    for (auto& x : r) cin >> x;
  }
  vector seen(n, vector<int>(m, -1));
  vector<int> color;
  int id = 0;
  vector<pair<int, int>> d4 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  function<void(int, int)> dfs = [&](int i, int j) {
    if (seen[i][j] != -1) return;
    seen[i][j] = id;
    for (auto& [di, dj] : d4) {
      int ii = i + di, jj = j + dj;
      if (0 <= ii && ii < n && 0 <= jj && jj < m) {
        if (a[i][j] == a[ii][jj]) dfs(ii, jj);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (seen[i][j] != -1) continue;
      dfs(i, j), id++, color.push_back(a[i][j]);
    }
  }

  vector<vector<int>> g(id);
  set<pair<int, int>> st;
  auto add = [&](int u, int v) {
    if (u != v) {
      if (st.count({u, v}) == 0) {
        g[u].push_back(v), g[v].push_back(u);
        st.insert({u, v}), st.insert({v, u});
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i != n - 1) {
        int u = seen[i][j], v = seen[i + 1][j];
        add(u, v);
      }
      if (j != m - 1) {
        int u = seen[i][j], v = seen[i][j + 1];
        add(u, v);
      }
    }
  }

  int res = 1e9;
  for (int i = 0; i < id; i++) {
    int cur = 0;
    vector<int> dist(id, -1);
    dist[i] = 0;
    vector<int> q{i}, nq;
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        for (auto& ne : g[node]) {
          if (dist[ne] == -1) {
            dist[ne] = dist[node] + 1;
            nq.push_back(ne);
            cur = max(cur, dist[ne]);
          }
        }
      }
    }
    if (color[i] == 1 && cur % 2 == 0) cur++;
    res = min(res, cur);
  }
  cout << res << "\n";
}
