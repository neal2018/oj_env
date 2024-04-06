#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> get_next(vector<i64>& pat) {
  int m = (int)pat.size();
  vector<int> nex(m);
  for (int i = 1, j = 0; i < m; i++) {
    while (j && pat[j] != pat[i]) j = nex[j - 1];
    if (pat[j] == pat[i]) j++;
    nex[i] = j;
  }
  return nex;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  auto get_map = [&] {
    std::vector<std::array<double, 2>> a(n);
    std::map<i64, vector<i64>> mp;
    for (auto& [x, y] : a)
      std::cin >> x >> y, mp[i64((x + 90) * 10000 + 0.5)].push_back(i64((y + 180) * 10000 + 0.5));
    return mp;
  };
  auto mp1 = get_map();
  auto mp2 = get_map();

  std::set<i64> can;
  bool init = false;

  constexpr i64 MOD = 360 * 10000;

  auto update = [&](std::vector<i64> v) {
    for (auto& x : v) {
      x = (x % MOD + MOD) % MOD;
    }
    if (!init) {
      for (auto& x : v) can.insert(x);
      init = true;
      return;
    }
    std::set<i64> good;
    for (auto& x : v) {
      if (can.contains(x)) good.insert(x);
    }
    can = good;
  };

  for (auto& [k, v1] : mp1) {
    auto& v2 = mp2[k];
    if (v1.size() != v2.size()) {
      std::cout << "Different\n";
      return 0;
    }
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    if (v1.size() == 1) {
      update({v1[0] - v2[0]});
      continue;
    }

    auto get_diff = [&](std::vector<i64> v) {
      std::vector<i64> diff;
      for (int i = 0; i < v.size(); i++) {
        i64 d = v[(i + 1) % v.size()] - v[i];
        d = (d % MOD + MOD) % MOD;
        diff.push_back(d);
      }
      return diff;
    };
    auto d1 = get_diff(v1);
    auto d2 = get_diff(v2);
    for (int i = 0; i < v1.size(); i++) d1.push_back(d1[i]);

    std::vector<i64> now;

    auto& pat = d2;
    auto& txt = d1;
    auto m = d2.size();
    auto nex = get_next(pat);
    for (int i = 0, j = 0; i < d1.size(); i++) {
      while (j && pat[j] != txt[i]) j = nex[j - 1];
      if (pat[j] == txt[i]) j++;
      if (j == m) {
        // do what you want with the match
        // start index is `i - m + 1`
        now.push_back(v1[(i - m + 1) % m] - v2[0]);
        j = nex[j - 1];
      }
    }

    update(now);
  }
  if (can.size() && init) {
    std::cout << "Same\n";
  } else {
    std::cout << "Different\n";
  }
}
