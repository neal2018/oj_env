#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<std::array<std::string, 2>> info(n);
    for (auto& [g, w] : info) std::cin >> g >> w;
    std::vector<int> e(n);

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (info[i][0] == info[j][0] || info[i][1] == info[j][1]) {
          e[i] |= (1 << j);
          e[j] |= (1 << i);
        }
      }
    }

    std::vector<int> dp(1 << n);
    for (int i = 0; i < n; i++) {
      dp[1 << i] = (1 << i);
    }

    int res = 0;

    for (unsigned mask = 0; mask < (1 << n); mask++) {
      if (!dp[mask]) {
        continue;
      }

      res = std::max(res, std::popcount(mask));

      for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) || !(e[j] & dp[mask])) {
          continue;
        }
        unsigned n_mask = mask | (1 << j);
        dp[n_mask] |= (1 << j);
      }
    }

    std::cout << n - res << "\n";
  }
}
