#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;
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
  vector<int> s(n), a(n), deg(n);
  for (auto& x : s) cin >> x;
  for (auto& x : a) cin >> x;
  vector<pair<int, int>> edges(m);
  for (auto& [u, v] : edges) cin >> u >> v, u--, v--, deg[u]++, deg[v]++;
  int k = m;
  for (int i = 0; i < n; i++) {
    if (s[i] != 0) {
      int t = (a[i] + deg[i]) / 2;
      k -= t;
      if ((a[i] + deg[i]) % 2 != 0 || t < 0) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  Dinic dinic(n + m + 3);
  int source = n + m, sink = n + m + 1, temp = n + m + 2;
  for (int i = 0; i < m; i++) {
    auto [u, v] = edges[i];
    dinic.add_edge(source, n + i, 1);
    dinic.add_edge(n + i, u, 1);
    dinic.add_edge(n + i, v, 1);
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 0) {
      dinic.add_edge(i, temp, k);
    } else {
      dinic.add_edge(i, sink, (a[i] + deg[i]) / 2);
    }
  }
  dinic.add_edge(temp, sink, k);

  if (k < 0 || dinic.max_flow(source, sink) != m) {
    cout << "NO\n";
    return 0;
  }

  vector<int> res(n);
  for (int i = 0; i < m; i++) {
    auto& [u, v] = edges[i];
    if (dinic.e[i * 6 + 2].remain == 0) swap(v, u);
  }
  cout << "YES\n";
  for (auto& [u, v] : edges) cout << u + 1 << " " << v + 1 << "\n";
}
