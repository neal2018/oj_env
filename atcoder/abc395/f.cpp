#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 inf = 1e18;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, limit;
  std::cin >> n >> limit;
  std::vector<std::array<i64, 2>> a(n);
  i64 l = 0, r = inf, sum = 0;
  for (auto& [u, d] : a) std::cin >> u >> d, r = std::min(r, u + d), sum += u + d;

  auto check = [&](i64 h) {
    i64 prev_low = -inf;
    i64 prev_high = inf;

    for (int i = 0; i < n; i++) {
      i64 curr_low = std::max({0ll, h - a[i][1], prev_low - limit});
      i64 curr_high = std::min({a[i][0], h, prev_high + limit});
      if (curr_low > curr_high) {
        return false;
      }
      prev_low = curr_low, prev_high = curr_high;
    }

    return true;
  };

  while (l < r) {
    auto mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  std::cout << sum - n * l;
}
