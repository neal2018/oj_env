#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<int> cnt(32);  // pos of last one
    auto get_pos_of_last_one = [&](int x) {
      for (int bit = 0; bit < 32; bit++) {
        if (x & (1 << bit)) {
          return bit;
        }
      }
      return -1;
    };
    auto add = [&](int x) {
      if (x == 0) {
        return;
      }
      auto pos = get_pos_of_last_one(x);
      cnt[pos]++;
    };
    auto remove = [&](int x) {
      if (x == 0) {
        return;
      }
      auto pos = get_pos_of_last_one(x);
      cnt[pos]--;
    };

    auto check = [&](int cur) {
      for (int bit = 31; bit >= 0; bit--) {
        if ((cur & (1 << bit)) && cnt[bit]) {
          return cur ^ (1 << bit) ^ ((1 << bit) - 1);
        }
      }
      for (int bit = 0; bit < 32; bit++) {
        if (cnt[bit]) {
          return cur ^ (1 << bit) ^ ((1 << bit) - 1);
        }
      }
      throw;
    };

    int res = 0;
    int all_xor = 0;
    for (auto& x : a) {
      all_xor ^= x;
      add(x);
    }
    for (auto& x : a) {
      remove(x);
      add(x + 1);
      auto cur = all_xor ^ x ^ (x + 1);
      res = std::max(res, check(cur));
      remove(x + 1);
      add(x);
    }
    std::cout << res << "\n";
  }
}
