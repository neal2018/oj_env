#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using Info = pair<int, int>;

struct SegTree {
  struct Node {
    int u = 0, v = 0, init = 0;
  };
  Node pull(const Node &a, const Node &b) {
    if (!a.init) return b;
    if (!b.init) return a;
    Node c;
    return c;
  }
  int n;
  vector<Node> t;
  function<Info(Info &, Info &)> common;
  SegTree(int _n, function<Info(Info &, Info &)> _common) : n(_n), t(2 * n), common(_common){};
  void modify(ll p, const Node &v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  Node query(int l, int r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
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
  function<int(int, int)> lca = [&](int x, int y) {
    while (top[x] != top[y]) {
      if (deep[top[x]] < deep[top[y]]) swap(x, y);
      x = parent[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
  };
  auto common = [&](Info &x, Info &y) -> Info {
    auto lca_1 = lca(x.first, y.second);
    auto lca_3 = lca(x.first, y.first);
    auto lca_2 = lca(x.second, y.first);
    auto lca_4 = lca(x.second, y.second);
  };
}
