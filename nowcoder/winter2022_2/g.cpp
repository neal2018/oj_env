#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  // lca start
  int root = n - 1;
  vector<int> parent(n), deep(n), hson(n), top(n), sz(n);
  function<int(int, int, int)> dfs = [&](int node, int fa, int dep) {
    deep[node] = dep, sz[node] = 1, parent[node] = fa;
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      sz[node] += dfs(ne, node, dep + 1);
      if (!hson[node] || sz[ne] > sz[hson[node]]) hson[node] = ne;
    }
    return sz[node];
  };
  function<void(int, int)> dfs2 = [&](int node, int t) {
    top[node] = t;
    if (!hson[node]) return;
    dfs2(hson[node], t);
    for (auto &ne : g[node]) {
      if (ne == parent[node] || ne == hson[node]) continue;
      dfs2(ne, ne);
    }
  };
  dfs(root, -1, 0), dfs2(root, root);
  function<int(int, int)> lca = [&](int x, int y) {
    while (top[x] != top[y]) {
      if (deep[top[x]] < deep[top[y]]) swap(x, y);
      x = parent[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
  };
  // lca end
  vector<ll> sum1(n), sum2(n);
  function<void(int)> get_sum = [&](int node) {
    if (parent[node] != -1) {
      sum1[node] = max(0ll, a[node] - a[parent[node]]) + sum1[parent[node]];
      sum2[node] = max(0ll, -a[node] + a[parent[node]]) + sum2[parent[node]];
    }
    for (auto &ne : g[node]) {
      if (ne == parent[node]) continue;
      get_sum(ne);
    }
  };
  get_sum(root);
  while (q--) {
    int u, v;
    cin >> u >> v, u--, v--;
    int fa = lca(u, v);
    cout << a[u] + sum2[u] - sum2[fa] + sum1[v] - sum1[fa] << '\n';
  }
}