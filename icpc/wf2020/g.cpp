#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::array<i64, 3>> a(n);
  for (auto& [x, y, z] : a) std::cin >> x >> y >> z;
  std::array<i64, 8> maxi{};
  for (int mask = 0; mask < 8; mask++) {
    i64 sum = 0;
    for (auto& v : a) {
      i64 curr = 0;
      for (int i = 0; i < 3; i++) {
        if (mask & (1 << i)) curr += v[i];
      }
      sum = std::max(sum, curr);
    }
    maxi[mask] = sum;
  }
  i64 res = 8e18;
  int id = n + 1;
  int i = 0;
  for (auto& v : a) {
    i64 curr = 0;
    for (int mask = 0; mask < 8; mask++) {
      i64 pos = maxi[mask];
      for (int i = 0; i < 3; i++) {
        if (mask & (1 << i)) pos -= v[i];
      }
      curr = std::max(curr, pos);
    }
    if (curr < res) {
      res = curr, id = i;
    }
    i++;
  }
  std::cout << res << " " << id + 1 << "\n";
}
