#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back({v, i}), g[v].push_back({u, i});
      edges[i] = {u, v};
    }
    vector<int> extra;
    vector<int> seen(n), dfn(n, -1);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int node, int fa) {
      if (seen[node]) return;
      seen[node] = 1, dfn[node] = cnt++;
      for (auto& [ne, id] : g[node]) {
        if (ne == fa) continue;
        if (seen[ne] && dfn[ne] < dfn[node]) {
          extra.push_back(id);
        } else {
          dfs(ne, node);
        }
      }
    };
    dfs(0, -1);
    if (extra.size() < 3) {
      string res(m, '0');
      for (auto& x : extra) res[x] = '1';
      cout << res << "\n";
      continue;
    }
    map<int, int> mp;
    for (auto& x : extra) {
      auto [u, v] = edges[x];
      mp[u]++, mp[v]++;
    }
    if (mp.size() == 3 && [&] {
          for (auto& [k, v] : mp) {
            if (v != 2) return false;
          }
          return true;
        }()) {
      vector<int> candidate;
      for (auto& [k, v] : mp) {
        candidate.push_back(k);
      }
      sort(candidate.begin(), candidate.end(), [&](auto x, auto y) { return dfn[x] < dfn[y]; });
      extra.clear();
      seen = vector<int>(n);
      dfn = vector<int>(n, -1);
      dfs(candidate[1], -1);
    }
    string res(m, '0');
    for (auto& x : extra) res[x] = '1';
    cout << res << "\n";
  }
}
