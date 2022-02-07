#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int m;
  cin >> m;
  vector<vector<int>> a(m);
  vector<string> res(m);
  vector<int> all;
  for (int i = 0; i < m; i++) {
    int n;
    cin >> n;
    a[i].resize(n), res[i] = string(n, '?');
    for (auto& x : a[i]) {
      cin >> x, all.push_back(x);
    }
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  int nv = (int)all.size();
  vector<int> cnt(nv);
  for (auto& v : a) {
    for (auto& x : v) {
      x = int(lower_bound(all.begin(), all.end(), x) - all.begin());
      cnt[x]++;
    }
  }
  for (auto& x : cnt) {
    if (x & 1) {
      cout << "NO\n";
      return 0;
    }
  }
  vector<vector<array<int, 3>>> g(m + nv);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      g[i].push_back({m + a[i][j], i, j});
      g[m + a[i][j]].push_back({i, i, j});
    }
  }
  vector<int> cur(m + nv);
  function<void(int, int)> dfs = [&](int node, int pre) {
    for (int ii = cur[node]; ii < g[node].size(); ii++) {
      auto& [ne, i, j] = g[node][ii];
      cur[node] = ii;
      if (res[i][j] == '?') {
        res[i][j] = (pre ? 'L' : 'R');
        dfs(ne, !pre);
        return;
      }
    }
  };
  for (int i = 0; i < m; i++) {
    dfs(i, 0);
  }
  cout << "YES\n";
  for (auto& x : res) cout << x << "\n";
}
