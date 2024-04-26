#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    auto get_prefix = [&](std::vector<int>& a) {
      // [0, i], cnt of parity of each bit
      std::array<std::array<i64, 2>, 31> cur = {};
      std::vector<decltype(cur)> prefix;
      for (auto& x : a) {
        for (int bit = 0; bit < 31; bit++) {
          if (x & (1 << bit)) {
            std::swap(cur[bit][0], cur[bit][1]);
            cur[bit][1]++;
          } else {
            cur[bit][0]++;
          }
        }
        prefix.push_back(cur);
      }
      return prefix;
    };
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    auto prefix = get_prefix(a);
    std::reverse(a.begin(), a.end());
    auto suffix = get_prefix(a);
    std::reverse(suffix.begin(), suffix.end());
    std::reverse(a.begin(), a.end());

    i64 res = 0;
    for (int i = 0; i < n; i++) {
      int msb = 31 - __builtin_clz(a[i]);
      i64 cur = prefix[i][msb][0] * suffix[i][msb][1] + prefix[i][msb][1] * suffix[i][msb][0];
      res += cur;
    }
    std::cout << res << "\n";
  }
}
