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
  vector<vector<int>> g(n, vector<int>(n));
  vector<int> lose_cnt(n);
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y, x--, y--, lose_cnt[y]++;
    g[x][y] = 1, g[y][x] = -1;
  }
  for (int cur = 0; cur < n; cur++) {
    if (lose_cnt[cur] == n - 1) continue;
    int win = n - 1 - lose_cnt[cur];
    // i*n + j: eij, i + n*n: vi
    int source = n + n * n + 1, sink = source + 1;
    Dinic dinic(sink + 1);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (g[i][j] == 1) {
          dinic.add_edge(i * n + j, i + n * n, 1);
        } else if (g[i][j] == -1) {
          dinic.add_edge(i * n + j, j + n * n, 1);
        } else {
          dinic.add_edge(i * n + j, j + n * n, 1);
          dinic.add_edge(i * n + j, i + n * n, 1);
        }
        dinic.add_edge(source, i * n + j, 1);
      }
    }
    for (int i = 0; i < n; i++) {
      if (i == cur) {
        dinic.add_edge(i + n * n, sink, win);
      } else {
        dinic.add_edge(i + n * n, sink, win - 1);
      }
    }
    ll flow = dinic.max_flow(source, sink);
    if (flow == n * (n - 1) / 2) {
      cout << cur + 1 << " ";
    }
  }
}
