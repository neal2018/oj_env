#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int mid = n - 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (std::max(std::abs(2 * i - mid), std::abs(2 * j - mid)) % 4 == (mid) % 4) {
        std::cout << "#";
      } else {
        std::cout << ".";
      }
    }
    std::cout << "\n";
  }
}
