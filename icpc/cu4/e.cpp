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

constexpr ll inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, c;
  cin >> m >> n >> c;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> cost(c);
  for (auto& x : cost) cin >> x;
  int tot = n * m;
  int source = 2 * tot, sink = 2 * tot + 1;
  Dinic dinic(sink + 1);
  // in: i*n+j, out: tot+i*n+j
  vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cc = (a[i][j] != '.' && a[i][j] != 'B') ? cost[a[i][j] - 'a'] : inf;
      // cout << cc << "\n";
      if (a[i][j] == 'B') {
        dinic.add_edge(source, i * m + j, inf);
      } else {
        for (auto& [di, dj] : directions) {
          int ii = i + di, jj = j + dj;
          if (0 <= ii && ii < n && 0 <= jj && jj < m) {
            dinic.add_edge(i * m + j + tot, ii * m + jj, inf);
            dinic.add_edge(ii * m + jj + tot, i * m + j, inf);
          }
        }
      }
      dinic.add_edge(i * m + j, i * m + j + tot, cc);
      if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
        dinic.add_edge(i * m + j + tot, sink, inf);
      }
    }
  }
  auto res = dinic.max_flow(source, sink);
  cout << (res >= inf ? -1 : res) << "\n";
}