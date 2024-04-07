#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  i64 sum = 0;
  std::vector<std::vector<std::array<int, 2>>> g(n);
  for (int i = 0, u, v, d; i < n - 1; i++) {
    std::cin >> u >> v >> d, u--, v--;
    g[u].push_back({v, d}), g[v].push_back({u, d});
    sum += d;
  }
  std::function<std::array<i64, 5>(int, int)> dfs = [&](int node, int fa) {
    std::array<i64, 5> dp{};
    for (auto& [ne, d] : g[node]) {
      if (ne == fa) continue;
      auto sub = dfs(ne, node);
      for (int i = 4; i >= 0; i--) {
        for (int j = 4 - i; j > 0; j--) {
          auto cur = dp[i] + sub[j] + ((j & 1) ? d : 0);
          dp[i + j] = std::max(dp[i + j], cur);
        }
      }
    }
    return dp;
  };
  auto res = dfs(0, -1);
  std::cout << 2 * sum - res[4] << "\n";
}
