#include <bits/stdc++.h>
using i64 = long long;

i64 get_sqrt(i64 x) {
  i64 l = 0, r = x;
  while (l < r) {
    i64 mid = l + (r - l + 1) / 2;
    if ((__int128)mid * mid <= x) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<i64> a(n), f(n), v(n);
  for (auto& x : a) std::cin >> x;

  std::map<i64, i64> mp;

  for (int i = 0; i < n; i++) {
    auto prev = i == 0 ? 0 : f[i - 1];
    v[i] = prev + a[i];
    f[i] = get_sqrt(v[i]);
    if (v[i] != f[i] * f[i]) mp[i] = v[i] - f[i] * f[i];
  }

  while (q--) {
    i64 i, x;
    std::cin >> i >> x, i--;
    a[i] = x;

    for (bool keep = true; i < n && keep; i++) {
      auto prev = i == 0 ? 0 : f[i - 1];
      v[i] = prev + a[i];
      if (v[i] >= (f[i] + 1) * (f[i] + 1)) {
        f[i] = get_sqrt(v[i]);
      } else if (f[i] > 1 && v[i] <= (f[i] - 1) * (f[i] - 1)) {
        f[i] = get_sqrt(v[i]);
      } else {
        keep = false;
      }
      mp[i] = v[i] - f[i] * f[i];
      if (mp[i] == 0) {
        mp.erase(i);
      }
    }

    auto res = f[n - 1];
    if (auto it = mp.end(); mp.size() && (--it)->second < 0) {
      res--;
    }
    std::cout << res << "\n";
  }
}
