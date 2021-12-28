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
  // cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  vector<int> a(n), res(n);
  for (auto& x : a) cin >> x;
  for (auto& [x, y] : edges) cin >> x >> y, x--, y--;
  auto v = a;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  function<void(int, int, vector<int>)> solve = [&](int l, int r, vector<int> u) {
    if (l == r || !u.size()) {
      for (auto& x : u) res[x] = v[l];
      return;
    }
    int mid = (l + r) / 2, N = (int)u.size();
    map<int, int> mp;
    Dinic dinic(N + 2);
    for (int i = 0; i < u.size(); i++) {
      mp[u[i]] = i;
      if (a[u[i]] <= v[mid]) {
        dinic.add_edge(N, i, 1);
      } else {
        dinic.add_edge(i, N + 1, 1);
      }
    }
    for (auto& [x, y] : edges) {
      if (mp.count(x) && mp.count(y)) dinic.add_edge(mp[y], mp[x], 1e9);
      cout<<"added "<< y<<" "<<x<<endl;
    }
    dinic.max_flow(N, N + 1);
    vector<int> L, R;
    for (int i = 0; i < N; i++) {
      if (dinic.d[i] < 1e9) {
        L.push_back(u[i]);
      } else {
        R.push_back(u[i]);
      }
    }
    solve(l, mid, L), solve(mid + 1, r, R);
  };
  vector<int> u(n);
  iota(u.begin(), u.end(), 0);
  solve(0, n - 1, u);
  for (auto& x : res) cout << x << " ";
  cout << "\n";
}
