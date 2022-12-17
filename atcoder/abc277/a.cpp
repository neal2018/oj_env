#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, x;
  std::cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    int p;
    std::cin >> p;
    if (p == x) {
      std::cout << i << "\n";
      return 0;
    }
  }
}
