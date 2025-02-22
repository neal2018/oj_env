#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  vector<i64> all;

  auto get_power10 = [&](auto i) {
    i64 res = 1;
    while (i--) {
      res *= 10;
    }
    return res;
  };

  for (i64 mid = 0; mid < 10; mid++) {
    for (i64 start = mid + 1; start < 10; start++) {
      i64 cur = start * get_power10(mid);
      for (i64 wing = 1; wing <= mid; wing++) {
        i64 digit = start - wing;
        cur += get_power10(mid + wing) * digit + get_power10(mid - wing) * digit;
      }
      all.push_back(cur);
    }
  }

  for (auto& x : all) {
    std::cout << x << " " << std::to_string(x).length() << "\n";
  }

  for (int case_no = 1; case_no <= T; case_no++) {
    i64 a, b, m;
    cin >> a >> b >> m;

    auto solve = [&](i64 n) {
      i64 t = 0;
      for (auto& x : all) {
        if (x % m == 0 && x < n) {
          t++;
        }
      }
      return t;
    };

    auto res = solve(b + 1) - solve(a);
    std::cout << "Case #" << case_no << ": ";
    std::cout << res << "\n";
  }
}
