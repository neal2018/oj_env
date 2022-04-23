#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

struct Edge {
  ll from, to, cap, remain;
};

struct Dinic {
  int n;
  vector<Edge> e;
  vector<vector<ll>> g;
  vector<ll> d, cur;
  Dinic(ll _n) : n(_n), g(n), d(n), cur(n) {}
  void add_edge(ll u, ll v, ll c) {
    g[u].push_back((int)e.size());
    e.push_back({u, v, c, c});
    g[v].push_back((int)e.size());
    e.push_back({v, u, 0, 0});
  }
  ll max_flow(ll s, ll t) {
    constexpr ll inf = 1e18;
    auto bfs = [&]() {
      fill(d.begin(), d.end(), inf);
      fill(cur.begin(), cur.end(), 0);
      d[s] = 0;
      vector<ll> q{s}, nq;
      for (ll step = 1; q.size(); swap(q, nq), nq.clear(), step++) {
        for (auto& node : q) {
          for (auto& edge : g[node]) {
            ll ne = e[edge].to;
            if (!e[edge].remain || d[ne] <= step) continue;
            d[ne] = step, nq.push_back(ne);
            if (ne == t) return true;
          }
        }
      }
      return false;
    };
    function<ll(ll, ll)> find = [&](ll node, ll limit) {
      if (node == t || !limit) return limit;
      ll flow = 0;
      for (ll i = cur[node]; i < g[node].size(); i++) {
        cur[node] = i;
        ll edge = g[node][i], oe = edge ^ 1, ne = e[edge].to;
        if (!e[edge].remain || d[ne] != d[node] + 1) continue;
        if (ll temp = find(ne, min(limit - flow, e[edge].remain))) {
          e[edge].remain -= temp, e[oe].remain += temp, flow += temp;
        } else {
          d[ne] = -1;
        }
        if (flow == limit) break;
      }
      return flow;
    };
    ll res = 0;
    while (bfs()) {
      while (ll flow = find(s, inf)) res += flow;
    }
    return res;
  }
};

constexpr ll inf = 1e18;

int main() {
  
}