#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  i64 H;
  std::cin >> H;

  std::vector<int> t(N), d(N);
  for (int i = 0; i < N; i++) {
    std::cin >> t[i] >> d[i];
  }

  std::vector<int> o(N);
  std::iota(o.begin(), o.end(), 0);
  std::sort(o.begin(), o.end(), [&](int i, int j) { return t[i] < t[j]; });

  std::vector<i64> pre(N + 1), suf(N + 1);
  for (int i = 0; i < N; i++) {
    pre[i + 1] = std::max(pre[i], 1LL * t[o[i]] * d[o[i]]);
  }
  for (int i = N - 1; i >= 0; i--) {
    suf[i] = std::max(suf[i + 1], 1LL * d[o[i]]);
  }

  auto check = [&](i64 x) {
    i64 sum = 0;
    for (int i = 0; i <= N; i++) {
      i64 l = 1, r = x;
      if (i) {
        l = std::max(l, 1LL * t[o[i - 1]]);
      }
      if (i < N) {
        r = std::min(r, 1LL * t[o[i]] - 1);
      }
      if (l <= r) {
        i64 m;
        if (!suf[i]) {
          m = r;
        } else {
          m = std::max(l - 1, std::min(r, pre[i] / suf[i]));
        }
        sum = sum + i128(m - l + 1) * pre[i];
        sum = sum + i128(r - m) * (m + r + 1) / 2 * suf[i];
        std::cout << sum << " " << l << " " << r <<" " << m << "\n";
        std::cout << (m - l + 1) * pre[i] << " " << (r - m) * (m + r + 1) / 2 * suf[i] << "\n";
      }
    }
    std::cout << "\n";
    return sum >= H;
  };
  check(9);
  i64 lo = 1, hi = H;
  while (lo < hi) {
    i64 x = (lo + hi) / 2;
    if (check(x)) {
      hi = x;
    } else {
      lo = x + 1;
    }
  }
  std::cout << lo << "\n";

  return 0;
}
