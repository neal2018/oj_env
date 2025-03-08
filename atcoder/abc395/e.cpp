#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 inf = 1e18;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, m, flip_weight;
  std::cin >> n >> m >> flip_weight;
  std::vector<std::vector<std::array<i64, 2>>> g(2 * n);
  for (int i = 0, u, v; i < m; i++) {
    std::cin >> u >> v, u--, v--;
    g[u].push_back({v, 1});
    g[v + n].push_back({u + n, 1});
  }
  for (int i = 0; i < n; i++) {
    g[i].push_back({i + n, flip_weight});
    g[i + n].push_back({i, flip_weight});
  }

  std::priority_queue<std::array<i64, 2>> q;
  std::vector<i64> cost(2 * n, inf);
  q.push({0, 0}), cost[0] = 0;
  while (q.size()) {
    auto [now, x] = q.top();
    q.pop();
    now = -now;
    for (auto [u, w] : g[x]) {
      auto n_now = now + w;
      if (n_now < cost[u]) {
        cost[u] = n_now;
        q.push({-n_now, u});
      }
    }
  }
  std::cout << std::min(cost[n - 1], cost[2 * n - 1]) << "\n";
}
