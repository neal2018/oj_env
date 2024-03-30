#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> a(x);
    for (auto& xx : a) std::cin >> xx;

    int res = x - 2;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < x; i++) {
      if ((a[(i + 1) % x] - a[i] + n) % n == 2) res++;
    }
    std::cout << res << "\n";
  }
}
