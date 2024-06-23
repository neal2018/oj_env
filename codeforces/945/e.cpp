#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (auto& x : a) std::cin >> x;
    std::cout << [&]() -> i64 {
      std::map<i64, std::vector<i64>> mp;
      for (auto& x : a) {
        mp[x % k].push_back(x);
      }
      i64 odd_cnt = 0;
      i64 res = 0;
      for (auto& [_, v] : mp) {
        if (v.size() % 2) {
          odd_cnt++;
        }
        if (odd_cnt > 1) {
          return -1;
        }
        if (v.size() == 1) {
          continue;
        }
        std::sort(v.begin(), v.end());
        if (v.size() % 2 == 0) {
          for (int i = 0; i < int(v.size()) - 1; i += 2) {
            res += (v[i + 1] - v[i]) / k;
          }
        } else {
          auto flip = v;
          for (int i = 0; i < v.size(); i += 2) {
            flip[i] = -flip[i];
          }
          std::vector<i64> pre(v.size() + 1);
          for (int i = 0; i < v.size(); i++) {
            pre[i + 1] = pre[i] + flip[i];
          }
          i64 mini = 1e18;
          for (int i = 0; i < v.size(); i++) {
            auto sum = pre[v.size()];
            auto first = pre[i];
            auto remain = sum - pre[i + 1];
            auto cur = first - remain;
            mini = std::min(mini, cur);
          }
          res += mini / k;
        }
      }
      return res;
    }() << "\n";
  }
}
