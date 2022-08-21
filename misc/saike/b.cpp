// https://codeforces.com/contest/1404/submission/92064937
#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n;
  m = n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  Dinic flow(2 * n * m + 2);
  int S = 2 * n * m, T = S + 1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'N') continue;
      ++ans;
      vector<int> v, h;
      if (i < n - 1 && s[i + 1][j] == 'P') v.push_back(i * m + j), --ans;
      if (j < m - 1 && s[i][j + 1] == 'P') h.push_back(i * m + j), --ans;
      if (i && s[i - 1][j] == 'P') v.push_back((i - 1) * m + j);
      if (j && s[i][j - 1] == 'P') h.push_back(i * m + j - 1);
      for (auto x : v)
        for (auto y : h) flow.add_edge(x, y + n * m, 1);
    }
  }
  for (int i = 0; i < n * m; ++i) {
    flow.add_edge(S, i, 1);
    flow.add_edge(i + n * m, T, 1);
  }
  cout << ans + flow.max_flow(S, T) << "\n";
  return 0;
}
