#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int inf = 1e9;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::array<i64, 2>>> g(n);
  for (i64 i = 0, u, v, w; i < m; i++) {
    std::cin >> u >> v >> w, u--, v--;
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }

  std::set<i64> seen{0};
  i64 cur = 0;
  i64 res = 8e18;
  auto dfs = [&](auto&& self, i64 x) {
    if (x == n - 1) {
      res = std::min(res, cur);
      return;
    }
    for (auto& [ne, w] : g[x]) {
      if (seen.contains(ne)) {
        continue;
      }
      seen.insert(ne);
      cur ^= w;
      self(self, ne);
      cur ^= w;
      seen.erase(ne);
    }
  };
  dfs(dfs, 0);
  std::cout << res << "\n";
}
