#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void apply(ll x, ll v) { t[x] += v; }
  void modify(ll l, ll r, ll v) {
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
  }
  ll query(ll p) {
    ll res = t[p += n];
    for (p /= 2; p > 0; p /= 2) res += t[p];
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  // lca start
  int root = 0, cur = 0;
  vector<int> parent(n), deep(n), hson(n), top(n), sz(n), dfn(n, -1);
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
    top[node] = t, dfn[node] = cur++;
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
  vector<ll> light(n);
  SegTree heavy(n), form_parent(n);
  while (q--) {
    int op, x, y;
    cin >> op >> x, x--;
    if (op == 1) {
      cin >> y, y--;
      int z = lca(x, y);
      while (x != z) {
        if (dfn[top[x]] <= dfn[top[z]]) {
          // [dfn[z], dfn[x]), from heavy
          heavy.modify(dfn[z], dfn[x], 1);
          break;
        }
        // x -> top[x];
        heavy.modify(dfn[top[x]], dfn[x], 1);
        light[parent[top[x]]] += a[top[x]];
        x = parent[top[x]];
      }
      while (y != z) {
        if (dfn[top[y]] <= dfn[top[z]]) {
          // (dfn[z], dfn[y]], from heavy
          form_parent.modify(dfn[z] + 1, dfn[y] + 1, 1);
          break;
        }
        // y -> top[y];
        form_parent.modify(dfn[top[y]], dfn[y] + 1, 1);
        y = parent[top[y]];
      }
    } else {
      cout << light[x] + heavy.query(dfn[x]) * a[hson[x]] +
                  form_parent.query(dfn[x]) * (x == root ? 0 : a[parent[x]])
           << "\n";
    }
  }
}
