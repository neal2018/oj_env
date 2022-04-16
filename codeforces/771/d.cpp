#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m, -1));
  for (auto& r : g) {
    for (auto& x : r) cin >> x;
  }
  auto check = [&](int i, int j) {
    set<int> st = {g[i][j], g[i][j + 1], g[i + 1][j], g[i + 1][j + 1]};
    st.erase(-1);
    if (st.size() == 1) return *st.begin();
    return 0;
  };
  vector<array<int, 3>> res;
  res.reserve(n * m);
  vector<pair<int, int>> can;
  can.reserve(n * m);
  auto update = [&](int i, int j) {
    if (auto t = check(i, j)) {
      can.push_back({i, j});
      res.push_back({i, j, t});
      g[i][j] = g[i][j + 1] = g[i + 1][j] = g[i + 1][j + 1] = -1;
    }
  };
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      update(i, j);
    }
  }
  vector<pair<int, int>> direction = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1},
                                      {-1, 0},  {1, 0},  {0, -1}, {0, 1}};
  while (can.size()) {
    auto [i, j] = can.back();
    can.pop_back();
    for (auto& [di, dj] : direction) {
      int ii = i + di, jj = j + dj;
      if (0 <= ii && ii < n - 1 && 0 <= jj && jj < m - 1) {
        update(ii, jj);
      }
    }
  }
  if (g != vector<vector<int>>(n, vector<int>(m, -1))) {
    cout << -1 << "\n";
  } else {
    reverse(res.begin(), res.end());
    cout << res.size() << "\n";
    for (auto& [i, j, k] : res) cout << i + 1 << " " << j + 1 << " " << k << "\n";
  }
}
