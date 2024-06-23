#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (n <= 2) {
      if (s[0] == '0') {
        std::cout << s[1] << "\n";
      } else {
        std::cout << s << "\n";
      }
      continue;
    }
    bool has_zero = std::count(s.begin(), s.end(), '0') > 0;
    if (has_zero && n > 3) {
      std::cout << "0\n";
      continue;
    }
    if (has_zero && (s[0] == '0' || s.back() == '0')) {
      std::cout << "0\n";
      continue;
    }
    int res = 1e9;
    for (int connect = 0; connect < n - 1; connect++) {
      auto cur = 0;
      bool all_one = true;
      for (int i = 0; i < n; i++) {
        int number = s[i] - '0';
        if (i == connect) {
          i++;
          number = number * 10 + s[i] - '0';
        }
        if (number == 1) {
          continue;
        }
        cur += number;
        all_one = false;
      }
      if (all_one) {
        cur += 1;
      }
      res = std::min(res, cur);
    }
    std::cout << res << "\n";
  }
}
