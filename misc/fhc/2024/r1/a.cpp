#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    int n;
    std::cin >> n;
    std::vector<std::array<i64, 2>> a(n);
    for (auto& [x, y] : a) std::cin >> x >> y;
    auto mini = std::array<i64, 2>{0, 1};
    auto maxi = std::array<i64, 2>{int(2e6), 1};

    auto is_smaller = [&](const std::array<i64, 2>& x, const std::array<i64, 2>& y) {
      if (x[0] * y[1] < y[0] * x[1]) {
        return true;
      }
      return false;
    };

    for (int i = 0; i < n; i++) {
      const i64 x = i + 1;
      auto [small, large] = a[i];
      if (small != 0) {
        if (is_smaller({x, small}, maxi)) {
          maxi = {x, small};
        }
      }

      if (is_smaller(mini, {x, large})) {
        mini = {x, large};
      }
    }
    std::cout << "Case #" << case_no << ": ";
    if (is_smaller(maxi, mini)) {
      std::cout << "-1\n";
    } else {
      std::cout << std::fixed << setprecision(10);
      std::cout << (long double)mini[0] / mini[1] << "\n";
    }
  }
}
