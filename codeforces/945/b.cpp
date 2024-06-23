#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    for (auto& r : a) {
      for (auto& x : r) std::cin >> x;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        auto max = 0;
        for (auto [di, dj] : std::vector<std::array<int, 2>>{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}) {
          auto ii = i + di, jj = j + dj;
          if (!(0 <= ii && ii < n && 0 <= jj && jj < m)) {
            continue;
          }
          max = std::max(max, a[ii][jj]);
        }
        a[i][j] = std::min(a[i][j], max);
      }
    }
    for (auto& r : a) {
      for (auto& x : r) std::cout << x << " ";
      std::cout << "\n";
    }
  }
}
