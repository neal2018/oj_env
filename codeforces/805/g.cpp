#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  int root = 0, cur = 0;
  vector<int> parent(n), deep(n), hson(n, -1), top(n), sz(n), dfn(n, -1);
  function<int(int, int, int)> dfs = [&](int node, int fa, int dep) {
    deep[node] = dep, sz[node] = 1, parent[node] = fa;
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      sz[node] += dfs(ne, node, dep + 1);
      if (hson[node] == -1 || sz[ne] > sz[hson[node]]) hson[node] = ne;
    }
    return sz[node];
  };
  function<void(int, int)> dfs2 = [&](int node, int t) {
    top[node] = t, dfn[node] = cur++;
    if (hson[node] == -1) return;
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
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (auto &x : a) cin >> x, x--;
    sort(a.begin(), a.end(), [&](int x, int y) { return dfn[x] < dfn[y]; });
    map<int, vector<int>> gg;
    vector<int> stk{0};
    auto add = [&](int x, int y) { gg[x].push_back(y), gg[y].push_back(x); };
    for (int i = 0; i < k; i++) {
      if (a[i] != 0) {
        int p = lca(a[i], stk.back());
        if (p != stk.back()) {
          while (dfn[p] < dfn[stk[int(stk.size()) - 2]]) {
            add(stk.back(), stk[int(stk.size()) - 2]);
            stk.pop_back();
          }
          add(p, stk.back()), stk.pop_back();
          if (dfn[p] > dfn[stk.back()]) stk.push_back(p);
        }
        stk.push_back(a[i]);
      }
    }
    while (stk.size() > 1) {
      if (stk.back() != 0) {
        add(stk.back(), stk[int(stk.size()) - 2]);
        stk.pop_back();
      }
    }
    bool has_root = find(a.begin(), a.end(), 0) != a.end();
    bool f = (!has_root && gg.count(0) && gg[0].size() == 1);
    [&] {
      for (auto &[kk, v] : gg) {
        if (f && kk == 0) continue;
        int cnt = 0;
        for (auto &x : v) {
          if (!(f && x == 0)) cnt++;
        }
        if (cnt > 2) {
          cout << "NO\n";
          return;
        }
      }
      cout << "YES\n";
    }();
  }
}
