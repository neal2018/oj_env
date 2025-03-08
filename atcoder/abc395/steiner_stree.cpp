#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// minimum steiner tree, O(n3^k + 2^k m logm)

const i64 inf = 1e18;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<std::array<i64, 2>>> g(n);
  for (int i = 0, u, v, w; i < m; i++) {
    std::cin >> u >> v >> w, u--, v--;
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }
  std::vector<i64> need(k);
  for (auto& x : need) std::cin >> x, x--;

  auto dp = std::vector(n, std::vector(1 << k, inf));
  for (int i = 0; i < k; i++) {
    dp[need[i]][1 << i] = 0;
  }

  auto dij = [&](int mask) {
    std::priority_queue<std::array<i64, 2>> q;
    for (int i = 0; i < n; i++) {
      if (dp[i][mask] < inf) {
        q.push({-dp[i][mask], i});
      }
    }

    while (q.size()) {
      auto [now, x] = q.top();
      q.pop();
      now = -now;
      for (auto [v, w] : g[x]) {
        if (now + w < dp[v][mask]) {
          dp[v][mask] = now + w;
          q.push({-now - w, v});
        }
      }
    }
  };

  for (int mask = 0; mask < (1 << k); mask++) {
    for (int i = 0; i < n; i++) {
      for (int s = mask & (mask - 1); s > 0; s = mask & (s - 1)) {
        dp[i][mask] = std::min(dp[i][mask], dp[i][s] + dp[i][mask & (~s)]);
      }
    }
    dij(mask);
  }

  auto res = inf;
  for (int i = 0; i < n; i++) {
    res = std::min(res, dp[i][(1 << k) - 1]);
  }
  std::cout << res << "\n";
}
