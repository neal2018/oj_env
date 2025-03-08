#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 inf = 1e18;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, need_k;
  std::cin >> n >> need_k;
  std::vector c(n, std::vector<i64>(n));
  for (auto& r : c) {
    for (auto& x : r) std::cin >> x;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        c[i][j] = std::min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }

  auto all_dp = std::vector(n, std::vector(n, std::vector(1 << (need_k + 1), inf)));
  for (int extra = 0; extra < n; extra++) {
    auto& dp = all_dp[extra];
    for (int i = 0; i < need_k; i++) {
      dp[i][1 << i] = 0;
    }
    dp[extra][1 << need_k] = 0;

    for (int mask = 0; mask < (1 << (need_k + 1)); mask++) {
      for (int i = 0; i < n; i++) {
        for (int s = mask & (mask - 1); s > 0; s = mask & (s - 1)) {
          if ((mask ^ s) > s) {
            break;
          }
          dp[i][mask] = std::min(dp[i][mask], dp[i][s] + dp[i][mask ^ s]);
        }
      }
      for (auto i : std::views::iota(0, n)) {
        for (auto j : std::views::iota(0, n)) {
          dp[i][mask] = std::min(dp[i][mask], dp[j][mask] + c[i][j]);
        }
      }
      // auto q = std::priority_queue<std::array<i64, 2>>{};
      // for (int i = 0; i < n; i++) {
      //   if (dp[i][mask] < inf) {
      //     q.push({-dp[i][mask], i});
      //   }
      // }
      // while (q.size()) {
      //   auto [now, u] = q.top();
      //   q.pop();
      //   now = -now;
      //   for (int v = 0; v < n; v++) {
      //     i64 n_now = now + c[u][v];
      //     if (n_now < dp[v][mask]) {
      //       dp[v][mask] = n_now;
      //       q.push({-n_now, v});
      //     }
      //   }
      // }
    }
  }

  int q;
  std::cin >> q;
  while (q--) {
    int s, t;
    std::cin >> s >> t, s--, t--;
    std::cout << all_dp[s][t][(1 << (need_k + 1)) - 1] << "\n";
  }
}
