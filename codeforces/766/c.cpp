#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> deg(n), res(n - 1);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v, u--, v--;
      g[u].push_back({v, i}), g[v].push_back({u, i});
      deg[u]++, deg[v]++;
    }
    if (*max_element(deg.begin(), deg.end()) > 2) {
      cout << -1 << "\n";
      continue;
    }
    int index = -1;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 1) {
        index = i;
        break;
      }
    }
    assert(index != -1);
    int cur = 2;
    function<void(int, int)> dfs = [&](int node, int fa) {
      for (auto& [ne, i] : g[node]) {
        if (ne == fa) continue;
        res[i] = cur;
        cur = (cur == 2 ? 3 : 2);
        dfs(ne, node);
      }
    };
    dfs(index, -1);
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}