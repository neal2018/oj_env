#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> a(m);
  vector<vector<int>> g(n);
  for (auto& [op, u, v] : a) {
    cin >> op >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> color(n, -1);
  bool good = true;
  function<void(int, int)> dfs = [&](int node, int col) {
    color[node] = col;
    for (auto& ne : g[node]) {
      if (color[ne] == -1) {
        dfs(ne, !col);
      } else if (color[ne] == col) {
        good = false;
      }
    }
  };
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) dfs(i, 0);
  }
  if (!good) {
    cout << "NO\n";
    return 0;
  }
  vector<vector<int>> topo(n);
  vector<int> deg(n);
  for (auto [op, u, v] : a) {
    if (color[u] == 1) swap(u, v);
    if (op == 1) swap(u, v);
    topo[u].push_back(v);
    deg[v]++;
  }
  vector<int> q, nq, pos(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) q.push_back(i);
  }
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      pos[node] = cur++;
      for (auto& ne : topo[node]) {
        deg[ne]--;
        if (deg[ne] == 0) nq.push_back(ne);
      }
    }
  }
  for (auto& x : deg) {
    if (x != 0) good = false;
  }
  if (!good) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << (color[i] ? 'L' : 'R') << " " << pos[i] << "\n";
  }
}
