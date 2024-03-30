#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, c;
  std::cin >> n >> c;
  std::vector<i64> a(n);
  for (auto& x : a) std::cin >> x;

  auto sum = std::accumulate(a.begin(), a.end(), 0ll);

  if (c <= 0) {
    for (auto& x : a) x = -x;
  }

  i64 max_subarray_sum = 0;
  i64 curr = 0;

  for (auto& x : a) {
    curr = std::max(curr, 0ll) + x;
    max_subarray_sum = std::max(max_subarray_sum, curr);
  }

  sum += std::abs(-c + 1) * max_subarray_sum;
  std::cout << sum << "\n";
}
