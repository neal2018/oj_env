#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    std::vector a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = i, x; j < n; j++) {
        std::cin >> x;
        a[i][j] = a[j][i] = x;
      }
    }
    std::vector<std::vector<int>> dp(n + 2);
    dp[0] = {0};
    dp[1] = {0};
    auto get_add = [&](int j, int i) {
      if (j <= i) return a[j][i];
      return 0;
    };
    for (int i = 0; i < n; i++) {
      std::set<array<int, 3>> st;  // val, j, top x
      for (int j = 0; j <= i + 1; j++) {
        // paint j...i, leave j-1 empty
        // dp[i] = a[j..i] + dp[j-2]
        st.insert({-dp[j][0] - get_add(j, i), j, 0});
      }
      while (st.size() && dp[i + 2].size() < k) {
        auto [val, j, index] = *st.begin();
        st.erase(st.begin());
        dp[i + 2].push_back(-val);
        if (index != int(dp[j].size()) - 1) {
          st.insert({-dp[j][index + 1] - get_add(j, i), j, index + 1});
        }
      }
    }
    for (int i = 0; i < k; i++) {
      std::cout << dp[n + 1][i] << " ";
    }
    std::cout << "\n";
  }
}
