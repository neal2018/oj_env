#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    i64 n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a) std::cin >> x;

    auto bf = [&] {
      i64 res = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if ((a[i] * a[j]) % ((i + 1) * (j + 1)) == 0) {
            res++;
          }
        }
      }
      return res;
    }();
    std::cout << bf << "\n";
  }
}
