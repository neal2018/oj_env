#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<array<ll, 3>> a(m);
  for (auto& [x, y, z] : a) cin >> z >> x >> y;
  sort(a.begin(), a.end());
  if (a[0][2] != 1) {
    cout << "0/21/0\n";
    return 0;
  }
  ll cur = 0, res = 0;
  for (auto& [x, y, z] : a) {
    if (z == 1) {
      cur += (y - x + 1);
      res += 3 * (y - x + 1);
    } else {
      cur -= (y - x + 1);
      res += (y - x + 1);
    }
    if (cur < 0) {
      res += (abs(cur) + 1) / 2 * 6;
      cur += (abs(cur) + 1) / 2 * 2;
    }
  }
  res -= cur / 2 * 2;
  cout << res << "\n";
}
