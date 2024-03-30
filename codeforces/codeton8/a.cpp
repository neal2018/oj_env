#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    std::vector res{-1};
    if (n == k) {
      res = std::vector<int>(n, 1);
    } else if (k == 1) {
      res = std::vector<int>(n);
      for (int i = 0; i < n; i++) res[i] = i + 1;
    }
    for (auto& x : res) std::cout << x << " ";
    std::cout << "\n";
  }
}
