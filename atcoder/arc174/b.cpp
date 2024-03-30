#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    std::array<i64, 5> a, p;
    for (auto& x : a) std::cin >> x;
    for (auto& x : p) std::cin >> x;

    // (a1 + 2a2 + 3a3 + 4a4 - 2 * (\sum a)) + t3 + 2t4 >= 0
    // min \sum p_i * t_i

    i64 need = 2 * a[0] + a[1] - a[3] - 2 * a[4];
    if (need <= 0) {
      std::cout << "0\n";
      continue;
    }

    if (2 * p[3] <= p[4]) {
      std::cout << p[3] * need << "\n";
    } else {
      std::cout << (need / 2 * p[4]) + (need % 2 ? (std::min(p[3], p[4])) : 0) << "\n";
    }
  }
}
