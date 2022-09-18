#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

namespace input {
unsigned long long k1, k2;
unsigned long long CoronavirusBeats() {
  unsigned long long k3 = k1, k4 = k2;
  k1 = k4;
  k3 ^= k3 << 23;
  k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
  return k2 + k4;
}
}  // namespace input

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ull n;
  cin >> n >> input::k1 >> input::k2;
  vector<array<ull, 4>> a(n);
  for (int cnt = 0; auto& [x, y, z, id] : a) {
    x = input::CoronavirusBeats();
    y = input::CoronavirusBeats();
    z = input::CoronavirusBeats();
    id = cnt++;
  }
  vector<ull> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](ull i, ull j) {
    return __int128(a[i][0]) + a[i][1] + a[i][2] < __int128(a[j][0]) + a[j][1] + a[j][2];
  });
  auto check = [&](ull i, ull j) {
    auto [x1, y1, z1, id1] = a[i];
    auto [x2, y2, z2, id2] = a[j];
    return x1 <= x2 && y1 <= y2 && z1 <= z2 && (x1 < x2 || y1 < y2 || z1 < z2);
  };
  vector<ull> res(n);
  ull maxi = 0;
  vector<vector<ull>> layer(n + 1);
  for (auto& i : order) {
    auto [x, y, z, id] = a[i];
    ull cur = 0;
    [&] {
      for (ull t = maxi; t >= 0; t--) {
        for (auto& j : layer[t]) {
          if (check(j, i)) {
            cur = t + 1;
            return;
          }
        }
        if (t == 0) break;
      }
    }();
    maxi = max(maxi, cur);
    layer[cur].push_back(i);
    res[id] = cur;
  }
  cout << maxi + 1 << "\n";
  for (auto& x : res) cout << x << " ";
  cout << "\n";
}
