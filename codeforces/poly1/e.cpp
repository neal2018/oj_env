#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, d;
  cin >> n >> d;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  array<vector<int>, 2> a{vector<int>(n), vector<int>(n)};
  for (auto& r : a) {
    int m;
    cin >> m;
    for (int i = 0, x; i < m; i++) cin >> x, x--, r[x] = 1;
  }
  vector<int> parent(n), deep(n);
  function<void(int, int)> get_parent = [&](int node, int fa) {
    parent[node] = fa;
    if (fa != -1) deep[node] = deep[parent[node]] + 1;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      get_parent(ne, node);
    }
  };
  get_parent(0, -1);
  auto solve = [&] {
    ll res = 0;
    vector<int> reached(n);
    function<bool(int)> dfs = [&](int node) {
      reached[node] = a[0][node];
      for (auto& ne : g[node]) {
        if (ne == parent[node]) continue;
        reached[node] |= dfs(ne);
      }
      return reached[node];
    };
    dfs(0);

    vector<int> leaf;
    function<bool(int)> get_leaf = [&](int node) {
      bool has = false;
      for (auto& ne : g[node]) {
        if (ne == parent[node]) continue;
        has |= get_leaf(ne);
      }
      if (!has && a[1][node]) leaf.push_back(node);
      return has || a[1][node];
    };
    get_leaf(0);
    set<int> need;
    for (auto x : leaf) {
      for (int i = 0; i < d && x != 0; i++) {
        x = parent[x];
      }
      need.insert(x);
    }
    for (auto x : need) {
      while (!reached[x]) {
        reached[x] = 1;
        x = parent[x];
        res++;
      }
    }

    vector<int> mark(n);
    for (auto x : leaf) {
      while (!mark[x] && x != 0) {
        mark[x] = 1;
        x = parent[x];
        res++;
      }
    }
    return res;
  };
  ll res = 0;
  res += solve();
  swap(a[0], a[1]);
  res += solve();
  cout << res * 2 << "\n";
}
