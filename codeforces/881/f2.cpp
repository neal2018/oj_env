#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct HeavyLight {
  int root = 0, n = 0;
  vector<int> parent, deep, hson, top, sz, dfn;
  HeavyLight(const vector<vector<int>> &g, int _root)
      : root(_root), n(int(g.size())), parent(n), deep(n), hson(n, -1), top(n), sz(n), dfn(n, -1) {
    int cur = 0;
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
  }

  int lca(int x, int y) const {
    while (top[x] != top[y]) {
      if (deep[top[x]] < deep[top[y]]) swap(x, y);
      x = parent[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
  }

  vector<array<int, 2>> get_dfn_path(int x, int y) const {
    array<vector<array<int, 2>>, 2> path;
    bool front = true;
    while (top[x] != top[y]) {
      if (deep[top[x]] > deep[top[y]]) swap(x, y), front = !front;
      path[front].push_back({dfn[y], dfn[top[y]]});
      y = parent[top[y]];
    }
    if (deep[x] > deep[y]) swap(x, y), front = !front;

    path[front].push_back({dfn[y], dfn[x]});
    reverse(path[1].begin(), path[1].end());
    for (const auto &[left, right] : path[1]) path[0].push_back({right, left});
    return path[0];
  }
};

struct Node {
  int sum = 0;
  int max_v = 0, max_pre_sum = 0, max_suf_sum = 0;
  int min_v = 0, min_pre_sum = 0, min_suf_sum = 0;
};

Node pull(const Node &a, const Node &b) {
  return {a.sum + b.sum,
          max({a.max_v, b.max_v, a.max_suf_sum + b.max_pre_sum}),
          max(a.sum + b.max_pre_sum, a.max_pre_sum),
          max(b.sum + a.max_suf_sum, b.max_suf_sum),
          min({a.min_v, b.min_v, a.min_suf_sum + b.min_pre_sum}),
          min(a.sum + b.min_pre_sum, a.min_pre_sum),
          min(b.sum + a.min_suf_sum, b.min_suf_sum)};
}

struct SegTree {
  int n;
  vector<Node> t;
  SegTree(int _n) : n(_n), t(2 * n) {}
  void modify(int p, const Node &v) {
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
  int T;
  cin >> T;
  // int cnt = 0;
  while (T--) {
    int q;
    cin >> q;
    vector<array<int, 3>> queries;
    vector<vector<int>> g(1);
    vector<int> a{1};
    while (q--) {
      char c;
      cin >> c;
      if (c == '+') {
        int v, x;
        cin >> v >> x, v--;
        g.push_back({});
        a.push_back(x);
        g[v].push_back(int(g.size()) - 1);
      } else {
        int u, v, k;
        cin >> u >> v >> k, u--, v--;
        queries.push_back({u, v, k});
      }
    }
    const int n = int(g.size());
    const auto hld = HeavyLight(g, 0);
    auto seg = SegTree(n);
    for (int i = 0; i < n; i++) seg.t[n + hld.dfn[i]] = {a[i], a[i], a[i], a[i], a[i], a[i], a[i]};
    for (int i = n - 1; i > 0; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
    for (const auto &[u, v, k] : queries) {
      auto rev = [&](Node node) {
        swap(node.max_pre_sum, node.max_suf_sum);
        swap(node.min_pre_sum, node.min_suf_sum);
        return node;
      };
      auto node = Node();
      for (const auto &[left, right] : hld.get_dfn_path(u, v)) {
        if (left > right) {
          node = pull(node, rev(seg.query(right, left + 1)));
        } else {
          node = pull(node, seg.query(left, right + 1));
        }
      }
      if (node.min_v <= k && k <= node.max_v) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
