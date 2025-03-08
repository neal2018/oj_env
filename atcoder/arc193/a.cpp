#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 inf = 1e18;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<i64> w(n);
  for (auto& x : w) std::cin >> x;
  std::vector<std::array<i64, 2>> a(n);
  for (auto& [l, r] : a) std::cin >> l >> r, l--, r--;
  std::vector<i64> start(2 * n, inf);
  std::vector<i64> end(2 * n, inf);
  for (int i = 0; auto& [l, r] : a) {
    start[l] = std::min(start[l], w[i]);
    end[r] = std::min(end[r], w[i]);
    i++;
  }

  std::vector<i64> left(2 * n, inf);   // left[i] smallest w whose R < i
  std::vector<i64> right(2 * n, inf);  // right[i] smallest w whose L > i

  {
    i64 cur = inf;
    for (int i = 0; i < 2 * n; i++) {
      left[i] = cur;
      cur = std::min(cur, end[i]);
    }
  }
  {
    i64 cur = inf;
    for (int i = 2 * n - 1; i >= 0; i--) {
      right[i] = std::min(right[i], cur);
      cur = std::min(cur, start[i]);
    }
  }

  int q;
  std::cin >> q;
  for (int s, t; q--;) {
    std::cin >> s >> t, s--, t--;
    auto [ls, rs] = a[s];
    auto [lt, rt] = a[t];
    if (ls > lt) {
      std::swap(ls, lt);
      std::swap(rs, rt);
    }
    // ls <= lr
    if (rs < lt) {
      std::cout << w[s] + w[t] << "\n";
    } else if (rs >= rt) {
      auto jump = std::min(left[ls], right[rs]);
      if (jump < inf) {
        std::cout << jump + w[s] + w[t] << "\n";
      } else {
        std::cout << -1 << "\n";
      }
    } else {
      auto jump1 = std::min(left[ls], right[rt]);
      auto jump2 = left[lt] + right[rs];
      auto jump = std::min(jump1, jump2);
      if (jump < inf) {
        std::cout << jump + w[s] + w[t] << "\n";
      } else {
        std::cout << -1 << "\n";
      }
    }
  }
}
