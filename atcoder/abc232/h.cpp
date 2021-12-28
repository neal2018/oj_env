#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge {
  int from, to, cap, remain, cost;
};

struct MCMF {
  int n;
  vector<Edge> e;
  vector<vector<int>> g;
  vector<ll> d, pre;
  MCMF(int _n) : n(_n), g(n), d(n), pre(n) {}
  void add_edge(int u, int v, int c, int w) {
    g[u].push_back((int)e.size());
    e.push_back({u, v, c, c, w});
    g[v].push_back((int)e.size());
    e.push_back({v, u, 0, 0, -w});
  }
  pair<ll, ll> max_flow(int s, int t) {
    ll inf = 1e18;
    auto spfa = [&]() {
      fill(d.begin(), d.end(), -inf); // important!
      vector<int> f(n), seen(n);
      d[s] = 0, f[s] = 1e9;
      vector<int> q{s}, nq;
      for (; q.size(); swap(q, nq), nq.clear()) {
        for (auto& node : q) {
          seen[node] = false;
          for (auto& edge : g[node]) {
            int ne = e[edge].to, cost = e[edge].cost;
            if (!e[edge].remain || d[ne] >= d[node] + cost) continue;
            d[ne] = d[node] + cost, pre[ne] = edge;
            f[ne] = min(e[edge].remain, f[node]);
            if (!seen[ne]) seen[ne] = true, nq.push_back(ne);
          }
        }
      }
      return f[t];
    };
    ll flow = 0, cost = 0;
    while (int temp = spfa()) {
      if (d[t] < 0) break; // important!
      flow += temp, cost += temp * d[t];
      for (ll i = t; i != s; i = e[pre[i]].from) {
        e[pre[i]].remain -= temp, e[pre[i] ^ 1].remain += temp;
      }
    }
    return {flow, cost};
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int h, w, n;
  cin >> h >> w >> n;
  ll total = 0;
  // 0, 1 -> h, h+1 -> h+w, h+w+1
  MCMF mcmf(h + w + 2);
  for (int i = 0, u, v, c; i < n; i++) {
    cin >> u >> v >> c;
    mcmf.add_edge(u, v + h, 1, c);
    total += c;
  }
  for (int i = 1; i <= h; i++) {
    mcmf.add_edge(0, i, (int)mcmf.g[i].size() - 1, 0);
  }
  for (int i = h + 1; i <= h + w; i++) {
    mcmf.add_edge(i, h + w + 1, (int)mcmf.g[i].size() - 1, 0);
  }
  auto [flow, cost] = mcmf.max_flow(0, h + w + 1);
  cout << total - cost << '\n';
  return 0;
}