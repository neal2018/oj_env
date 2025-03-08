#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int inf = 1e9;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  int res = inf;
  auto mp = std::map<int, int>{};

  for (int i = 0; i < n; i++) {
    if (mp.contains(a[i])) {
      res = std::min(res, i - mp[a[i]] + 1);
    }
    mp[a[i]] = i;
  }
  std::cout << (res == inf ? -1 : res) << "\n";
}
