#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
  int from, to, cap, remain;
};

struct Dinic {
  int n;
  vector<Edge> e;
  vector<vector<int>> g;
  vector<int> d, cur;
  Dinic(int _n) : n(_n), g(n), d(n), cur(n) {}
  void add_edge(int u, int v, int c) {
    g[u].push_back((int)e.size());
    e.push_back({u, v, c, c});
    g[v].push_back((int)e.size());
    e.push_back({v, u, 0, 0});
  }
  ll max_flow(int s, int t) {
    int inf = 1e9;
    auto bfs = [&]() {
      fill(d.begin(), d.end(), inf), fill(cur.begin(), cur.end(), 0);
      d[s] = 0;
      vector<int> q{s}, nq;
      for (int step = 1; q.size(); swap(q, nq), nq.clear(), step++) {
        for (auto& node : q) {
          for (auto& edge : g[node]) {
            int ne = e[edge].to;
            if (!e[edge].remain || d[ne] <= step) continue;
            d[ne] = step, nq.push_back(ne);
            if (ne == t) return true;
          }
        }
      }
      return false;
    };
    function<int(int, int)> find = [&](int node, int limit) {
      if (node == t || !limit) return limit;
      int flow = 0;
      for (int i = cur[node]; i < g[node].size(); i++) {
        cur[node] = i;
        int edge = g[node][i], oe = edge ^ 1, ne = e[edge].to;
        if (!e[edge].remain || d[ne] != d[node] + 1) continue;
        if (int temp = find(ne, min(limit - flow, e[edge].remain))) {
          e[edge].remain -= temp, e[oe].remain += temp, flow += temp;
        } else {
          d[ne] = -1;
        }
        if (flow == limit) break;
      }
      return flow;
    };
    ll res = 0;
    while (bfs())
      while (int flow = find(s, inf)) res += flow;
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto& x : g) cin >> x;
  vector<vector<int>> id(n, vector<int>(m, -1));
  int cur = 0;
  vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  function<void(int, int)> dfs = [&](int x, int y) {
    id[x][y] = cur;
    for (auto& [dx, dy] : directions) {
      int xx = x + dx, yy = y + dy;
      if (!(0 <= xx && xx < n && 0 <= yy && yy < m && id[xx][yy] == -1)) continue;
      if (g[xx][yy] != g[x][y]) continue;
      dfs(xx, yy);
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (id[i][j] == -1) dfs(i, j), cur++;
    }
  }
  vector<int> out(cur), color(cur);
  for (int i = 0; i < n; i++) out[id[i][0]] = 1;
  for (int i = 0; i < n; i++) out[id[i][m - 1]] = 1;
  for (int i = 0; i < m; i++) out[id[0][i]] = 1;
  for (int i = 0; i < m; i++) out[id[n - 1][i]] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '1') color[id[i][j]] = 1;
    }
  }
  Dinic dinic(cur + 2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (out[id[i][j]]) continue;
      for (auto& [dx, dy] : directions) {
        int xx = i + dx, yy = j + dy;
        if (!(0 <= xx && xx < n && 0 <= yy && yy < m)) continue;
        if (g[xx][yy] == g[i][j]) continue;
        if (out[id[xx][yy]]) continue;
        if (g[xx][yy] == '0') {
          dinic.add_edge(id[xx][yy], id[i][j], 1);
        } else {
          dinic.add_edge(id[i][j], id[xx][yy], 1);
        }
      }
    }
  }
  for (int i = 0; i < cur; i++) {
    if (!out[i]) {
      if (color[i]) {
        dinic.add_edge(i, cur + 1, 1);
      } else {
        dinic.add_edge(cur, i, 1);
      }
    }
  }
  ll res = dinic.max_flow(cur, cur + 1);
  res += accumulate(out.begin(), out.end(), 0ll);
  cout << res << '\n';
}