#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using Info = pair<int, int>;

struct SegTree {
  struct Node {
    Info v = {-1, -1};
    int init = 0;
  };
  Node pull(Node &a, Node &b) {
    if (!a.init) return b;
    if (!b.init) return a;
    return {common(a.v, b.v), 1};
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
  dfs(root, -1, 0), dfs2(root, root);
  function<int(int, int)> lca = [&](int x, int y) {
    while (top[x] != top[y]) {
      if (deep[top[x]] < deep[top[y]]) swap(x, y);
      x = parent[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
  };
  auto dist = [&](int u, int v) { return deep[u] + deep[v] - 2 * deep[lca(u, v)]; };
  auto is_on = [&](int x, int u, int v) { return dist(u, x) + dist(x, v) == dist(u, v); };
  auto common = [&](Info &x, Info &y) -> Info {
    if (x == Info{-1, -1} || y == Info{-1, -1}) return {-1, -1};
    vector<int> v = {
        lca(x.first, y.second),
        lca(x.first, y.first),
        lca(x.second, y.first),
        lca(x.second, y.second),
    };
    sort(v.begin(), v.end(), [&](int xx, int yy) {
      return pair{deep[xx], xx} < pair{deep[yy], yy};
    });
    if (v[2] == v[3]) {
      if (deep[v[2]] < deep[lca(x.first, x.second)] || deep[v[2]] < deep[lca(y.first, y.second)]) {
        return {-1, -1};
      }
    }
    return {v[2], v[3]};
  };
  vector<array<int, 3>> path(m);
  for (auto &[w, u, v] : path) cin >> u >> v >> w, u--, v--;
  sort(path.begin(), path.end(), greater<>());
  SegTree seg(m, common);
  for (int i = 0; i < m; i++) seg.t[i + m] = {{path[i][1], path[i][2]}, 1};
  for (int i = m - 1; i > 0; i--) {
    seg.t[i] = seg.pull(seg.t[2 * i], seg.t[2 * i + 1]);
  }
  int right = m, last = 0;
  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      right--;
    } else {
      int u = 0;
      cin >> u, u ^= last, u--;
      auto check = [&](int mid) {
        auto node = seg.query(mid, right);
        if (node.v == Info{-1, -1}) return false;
        return is_on(u, node.v.first, node.v.second);
      };
      int l = 0, r = right;
      while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      last = r - 1;
      if (last != -1) last = path[last][0];
      cout << last << '\n';
    }
  }
}
