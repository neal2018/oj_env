#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, l, r;
  cin >> n >> l >> r;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }

  auto get_sg = [&](int len) {
    if (len >= l + r) return 0;
    return len / l;
  };

  int res = 0;

  vector<int> seen(n);
  function<int(int)> dfs = [&](int node) {
    if (seen[node]) return 0;
    seen[node] = 1;
    int sz = 1;
    for (auto& ne : g[node]) {
      sz += dfs(ne);
    }
    return sz;
  };
  for (int i = 0; i < n; i++) {
    if (seen[i] == 0) {
      auto sz = dfs(i);
      res ^= get_sg(sz);
    }
  }
  cout << (res ? "Alice\n" : "Bob\n");
}
