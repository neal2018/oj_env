#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;

  for (int case_no = 1; case_no <= T; case_no++) {
    constexpr int n = 6, m = 7;
    std::vector<std::string> a(n);
    for (auto& x : a) std::cin >> x;

    bool c_win = false, f_win = false;

    auto check = [&](char c, std::array<int, 2> direction, int i, int j) {
      for (int t = 0; t < 4; t++) {
        if (!(0 <= i && i < n && 0 <= j && j < m)) {
          return false;
        }
        if (a[i][j] != c) {
          return false;
        }
        i += direction[0], j += direction[1];
      }
      return true;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // vertical
        {
          if (check('C', {1, 0}, i, j)) {
            c_win = true;
          }
          if (check('F', {1, 0}, i, j)) {
            f_win = true;
          }
        }

        for (auto direction : std::vector<std::array<int, 2>>{{0, 1}, {-1, 1}, {1, 1}}) {
          for (char c : {'C', 'F'}) {
            char oppo = (c == 'C') ? 'F' : 'C';
            if (check(c, direction, i, j)) {
              if ([&] {
                    for (int t = i + 1; t < n; t++) {
                      if (check(oppo, direction, t, j)) {
                        return false;
                      }
                    }
                    return true;
                  }()) {
                (c == 'C') ? (c_win = true) : (f_win = true);
              }
            }
          }
        }
      }
    }
    std::cout << "Case #" << case_no << ": ";

    if (c_win && f_win) {
      std::cout << "?\n";
    } else if (c_win) {
      std::cout << "C\n";
    } else if (f_win) {
      std::cout << "F\n";
    } else {
      std::cout << "0\n";
    }
  }
}
