#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    i64 n, m;
    std::cin >> n >> m;
    std::vector<std::vector<i64>> g(n);
    std::vector<std::array<i64, 2>> edges(m);
    for (auto& [u, v] : edges) {
      std::cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    i64 cnt = 0, now = 0;
    std::vector<i64> dfn(n, -1), low(n), belong(n, -1), stk;
    std::function<void(i64, i64)> tarjan = [&](i64 node, i64 fa) {
      dfn[node] = low[node] = now++, stk.push_back(node);
      for (auto& ne : g[node]) {
        if (ne == fa) continue;  // remove if directed
        if (dfn[ne] == -1) {
          tarjan(ne, node);
          low[node] = std::min(low[node], low[ne]);
        } else if (belong[ne] == -1) {
          low[node] = std::min(low[node], dfn[ne]);
        }
      }
      if (dfn[node] == low[node]) {
        while (true) {
          auto v = stk.back();
          belong[v] = cnt;
          stk.pop_back();
          if (v == node) break;
        }
        ++cnt;
      }
    };
    tarjan(0, -1);

    std::vector<std::vector<i64>> tree(cnt);
    {
      std::set<std::array<i64, 2>> seen_edge;
      for (auto [u, v] : edges) {
        u = belong[u], v = belong[v];
        if (u == v) {
          continue;
        }
        if (seen_edge.count({u, v})) {
          continue;
        }
        seen_edge.insert({u, v});
        tree[u].push_back(v), tree[v].push_back(u);
      }
    }
    std::vector<i64> node_cnt(cnt);
    std::vector<i64> belong_cnt(cnt);
    for (i64 i = 0; i < n; i++) {
      belong_cnt[belong[i]]++;
    }
    i64 res = 0;
    std::function<void(i64, i64)> dp = [&](i64 node, i64 fa) {
      node_cnt[node] = belong_cnt[node];
      for (auto& ne : tree[node]) {
        if (ne == fa) continue;
        dp(ne, node);
        node_cnt[node] += node_cnt[ne];
      }
      res = std::max(res, node_cnt[node] * (n - node_cnt[node]));
    };
    dp(0, -1);
    std::cout << (n * (n - 1)) / 2 - res << "\n";
  }
}
