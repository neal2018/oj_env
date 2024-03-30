#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // 0, 1
  // 80 - 109
  // 9800 - 10099
  // 99800 - 1000999

  int T;
  std::cin >> T;
  while (T--) {
    i64 n;
    std::cin >> n;
    i64 res = 0;
    if (n >= 1) res++;

    for (int i = 1;; i++) {
      const auto special = [&] {
        i64 tmp = 0;
        for (int t = 0; t < i - 1; t++) {
          tmp = tmp * 10 + 9;
        }
        tmp = tmp * 10 + 8;
        for (int t = 0; t < i; t++) {
          tmp = tmp * 10;
        }
        return tmp;
      }();
      const auto left = [&] {
        i64 tmp = 0;
        for (int t = 0; t < i; t++) {
          tmp = tmp * 10 + 9;
        }
        for (int t = 0; t < i; t++) {
          tmp = tmp * 10;
        }
        return tmp;
      }();
      const auto right = [&] {
        i64 tmp = 1;
        for (int t = 0; t < i; t++) {
          tmp = tmp * 10;
        }
        for (int t = 0; t < i; t++) {
          tmp = tmp * 10 + 9;
        }
        return tmp;
      }();

      if (n >= special) res++;
      res += std::max(std::min(right, n) + 1 - left, 0ll);

      if (right >= n) break;
    }
    std::cout << res << "\n";
  }
}
