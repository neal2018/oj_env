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
  int n1, n2, m, q;
  cin >> n1 >> n2 >> m >> q;
  Dinic dinic(n1 + n2 + 2);
  int source = n1 + n2, sink = source + 1;
  vector<pair<int, int>> edges(m);
  for (auto&[x, y]:edges) {
    cin >> x >> y, x--, y--;
    edges.push_back({x, n1 + y});
    dinic.add_edge(x, n1 + y, 1);
  }
  for (int i = 0; i < n1; i++) {
    dinic.add_edge(source, i, 1);
  }

  for (int i = 0; i < n2; i++) {
    dinic.add_edge(n1 + i, sink, 1);
  }

  dinic.max_flow(source, sink);
  vector<pair<int, int>> cover;
  ll sum = 0;
  for (int i = 0; i < edges.size(); i++) {
    if (dinic.e[2 * i].remain == 0) {
      auto [u, v] = edges[i];
      int key = dinic.d[v] != inf ? v : u;
      cover.push_back({key, i});
      sum += i + 1;
    }
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      cout << "1\n";
      auto [rm, id] = cover.back();
      sum -= id + 1;
      cout << (rm < n1 ? rm + 1 : (-(rm - n1 + 1))) << "\n";
      cout << sum << "\n" << endl;
      cover.pop_back();
    } else {
      cout << cover.size() << "\n";
      for (auto& [p, e] : cover) cout << e + 1 << " ";
      cout << "\n" << endl;
    }
  }
}
