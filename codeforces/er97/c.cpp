#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

class MCMF {
public:
  static constexpr int INF = 1e9;
  const int n;
  vector<tuple<int, int, int>> e;
  vector<vector<int>> g;
  vector<int> h, dis, pre;
  bool dijkstra(int s, int t) {
    dis.assign(n, INF);
    pre.assign(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;
    dis[s] = 0;
    que.emplace(0, s);
    while (!que.empty()) {
      auto [d, u] = que.top();
      que.pop();
      if (dis[u] != d) continue;
      for (int i : g[u]) {
        auto [v, f, c] = e[i];
        if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
          dis[v] = d + h[u] - h[v] + f;
          pre[v] = i;
          que.emplace(dis[v], v);
        }
      }
    }
    return dis[t] != INF;
  }
  MCMF(int n) : n(n), g(n) {}
  void add_edge(int u, int v, int f, int c) {
    g[u].push_back(e.size());
    e.emplace_back(v, f, c);
    g[v].push_back(e.size());
    e.emplace_back(u, -f, 0);
  }
  pair<ll, ll> max_flow(const int s, const int t) {
    int flow = 0, cost = 0;
    h.assign(n, 0);
    while (dijkstra(s, t)) {
      for (int i = 0; i < n; ++i) h[i] += dis[i];
      for (int i = t; i != s; i = get<0>(e[pre[i] ^ 1])) {
        --get<2>(e[pre[i]]);
        ++get<2>(e[pre[i] ^ 1]);
      }
      ++flow;
      cost += h[t];
    }
    return {flow, cost};
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x, x--;
    MCMF mcmf(3 * n + 2);
    int source = 3 * n, sink = 3 * n + 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2 * n; j++) {
        mcmf.add_edge(i, n + j, abs(a[i] - j), 1);
      }
    }
    for (int i = 0; i < n; i++) {
      mcmf.add_edge(source, i, 0, 1);
    }
    for (int i = 0; i < 2 * n; i++) {
      mcmf.add_edge(n + i, sink, 0, 1);
    }
    auto [f, c] = mcmf.max_flow(source, sink);
    cout << c << "\n";
  }
}
