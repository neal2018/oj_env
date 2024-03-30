#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    std::cout << [&] {
      int n, t;
      std::cin >> n >> t;
      std::vector<int> a(n);
      for (auto& x : a) std::cin >> x;
      int res = -1;
      for (int bit = 30; bit >= 0; bit--) {
        std::vector<int> next_a;
        int cnt = 0, curr = 0;
        for (auto& x : a) {
          curr ^= x;
          if (x & (1 << bit)) {
            cnt++;
          }
          if (cnt % 2 == 0) {
            next_a.push_back(curr);
            cnt = 0, curr = 0;
          }
        }
        bool has_one = t & (1 << bit);
        if (cnt) {
          if (!has_one) {
            return res;
          }
        } else {
          if (has_one) {
            res = std::max(res, int(next_a.size()));
          } else {
            std::swap(a, next_a);
          }
        }
      }
      res = std::max(res, int(a.size()));
      return res;
    }() << "\n";
  }
}
