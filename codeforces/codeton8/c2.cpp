#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n, m, y;
    std::cin >> n >> m >> y;
    std::vector<int> a(m);
    for (auto& x : a) std::cin >> x;

    int res = m - 2;
    std::sort(a.begin(), a.end());
    std::vector<int> s_odd, s_even;
    for (int i = 0; i < m; i++) {
      auto len = (a[(i + 1) % m] - a[i] + n) % n + 1;
      if (len <= 3) {
        if (len == 3) res++;
        continue;
      }
      ((len % 2 == 1) ? s_odd : s_even).push_back(len);
    }
    std::sort(s_odd.begin(), s_odd.end());
    std::sort(s_even.begin(), s_even.end());

    for (auto& x : s_odd) {
      if (y > 0) {
        int len_add = (x + 1) / 2 - 2;
        int can = min(y, len_add);
        res += can;
        res += can;
        if (can == len_add) res++;
        y -= can;
      }
    }

    for (auto& x : s_even) {
      if (y > 0) {
        int len_add = x / 2 - 1;
        int can = min(y, len_add);
        res += can;
        res += can;
        y -= can;
      }
    }

    std::cout << res << "\n";
  }
}
