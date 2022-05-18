#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

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
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    int n;
    cin >> n;
    vector<pair<ll, ll>> child(n), candy(n);
    pair<ll, ll> blueberry;
    for (auto& [x, y] : child) cin >> x >> y;
    cin >> blueberry.first >> blueberry.second;
    for (auto& [x, y] : candy) cin >> x >> y;
    int source = 2 * n, sink = 2 * n + 1;
    Dinic dinic(2 * n + 2);
    auto dis = [&](const pair<ll, ll>& x, const pair<ll, ll>& y) {
      return (x.first - y.first) * (x.first - y.first) +
             (x.second - y.second) * (x.second - y.second);
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dis(child[i], candy[j]) <= dis(child[i], blueberry)) {
          dinic.add_edge(i, j + n, 1);
        }
      }
    }
    for (int i = 0; i < n; i++) dinic.add_edge(source, i, 1);
    for (int i = 0; i < n; i++) dinic.add_edge(i + n, sink, 1);
    auto f = dinic.max_flow(source, sink);
    if (f != n) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << "POSSIBLE\n";
      vector<int> child_matched(n), candy_matched(n);
      for (auto& e : dinic.e) {
        if (e.cap && e.remain == 0 && e.from != source && e.to != sink) {
          child_matched[e.from] = e.to - n;
          candy_matched[e.to - n] = e.from;
        }
      }
      vector<vector<int>> order(n, vector<int>(n));
      for (int i = 0; i < n; i++) {
        auto& o = order[i];
        iota(o.begin(), o.end(), 0ll);
        vector<ll> dist;
        for (int j = 0; j < n; j++) dist.push_back(dis(child[i], candy[j]));
        sort(o.begin(), o.end(), [&](ll a, ll b) { return dist[a] < dist[b]; });
      }
      vector<int> ptr(n, 0);
      vector<int> child_used(n), candy_used(n);
      for (int _ = 0; _ < n; _++) {
        for (int i = 0; i < n; i++) {
          if (child_used[i]) continue;
          for (; ptr[i] < n && candy_used[order[i][ptr[i]]];) ptr[i]++;
        }
        int x = 0;
        while (child_used[x]) x++;
        if (child_matched[x] != order[x][ptr[x]]) {
          vector<int> seen(n), stack{x};
          while (seen[x] == 0) {
            seen[x] = 1;
            x = candy_matched[order[x][ptr[x]]];
            stack.push_back(x);
          }
          int sz = (int)stack.size();
          for (int i = sz - 1; i >= 0; i--) {
            if (i < sz - 1 && stack[i] == x) break;
            child_matched[stack[i]] = order[stack[i]][ptr[stack[i]]];
            candy_matched[child_matched[stack[i]]] = stack[i];
          }
        }
        child_used[x] = 1, candy_used[child_matched[x]] = 1;
        cout << x + 1 << " " << child_matched[x] + 2 << "\n";
      }
    }
  }
}
