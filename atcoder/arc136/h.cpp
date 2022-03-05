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
  string s;
  cin >> s;
  int n = int(s.size());
  set<string> st;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      auto t = s.substr(i, j - i + 1);
      if (t == string(t.rbegin(), t.rend())) {
        st.insert(t);
      }
    }
  }
  vector<string> a(st.begin(), st.end());
  int sz = int(a.size());
  vector<vector<int>> g(sz, vector<int>(sz));
  for (int i = 0; i < sz; i++) {
    for (int j = i + 1; j < sz; j++) {
      if (a[i].find(a[j]) != string::npos) g[i][j] = 1;
      if (a[j].find(a[i]) != string::npos) g[j][i] = 1;
    }
  }
  for (int k = 0; k < sz; k++) {
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        if (g[i][k] && g[k][j]) g[i][j] = 1;
      }
    }
  }
  Dinic dinic(sz * 2 + 2);
  int source = sz * 2, sink = sz * 2 + 1;
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      if (g[i][j]) dinic.add_edge(i, sz + j, 1);
    }
  }
  for (int i = 0; i < sz; i++) dinic.add_edge(source, i, 1);
  for (int i = 0; i < sz; i++) dinic.add_edge(sz + i, sink, 1);
  int res = dinic.max_flow(source, sink);
  cout << sz - res << "\n";
}
