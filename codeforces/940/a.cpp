#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for ([[maybe_unused]] auto i : std::views::iota(0, n)) {
      int x;
      std::cin >> x;
      mp[x]++;
    }
    int res = 0;
    for (auto& [k, v] : mp) {
      res += v / 3;
    }
    std::cout << res << "\n";
  }
}
