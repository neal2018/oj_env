#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    i64 n, k;
    std::cin >> n >> k;
    auto val = [&]() -> i64 {
      i64 cur = 1;
      while (cur * 2 + 1 <= k) {
        cur = cur * 2 + 1;
      }
      return cur;
    }();
    if (n == 1) {
      std::cout << k << "\n";
      continue;
    }
    std::vector<i64> res{val};
    res.push_back(k - val);
    while (res.size() < n) res.push_back(0);
    for (auto& x : res) std::cout << x << " ";
    std::cout << "\n";
  }
}
