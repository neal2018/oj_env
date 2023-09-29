#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 31;
constexpr int base = 1'000'000'0;

struct Node {
  array<array<int, 2>, 31> info;
  Node(int x = 0, int dep = 0) {
    for (int bit = 0; bit < N; bit++) {
      if (x & (1 << bit)) {
        info[bit] = {dep + base, dep + base};
      } else {
        info[bit] = {-1, -1};
      }
    }
  }
};

Node pull(const Node &a, const Node &b) {
  auto neg_one_min = [](int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    return min(x, y);
  };

  auto neg_one_max = [](int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    return max(x, y);
  };
  Node c;
  for (int bit = 0; bit < N; bit++) {
    c.info[bit] = {neg_one_min(a.info[bit][0], b.info[bit][0]),
                   neg_one_max(a.info[bit][1], b.info[bit][1])};
  }
  return c;
}

Node rev(Node node) {
  for (auto &[x, y] : node.info) {
    swap(x, y);
    if (x != -1) x = 1'000'000 - (x - base);
    if (y != -1) y = 1'000'000 - (y - base);
  }
  return node;
}

struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n){};
  void modify(ll p, const Node &v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  Node query(ll l, ll r) const {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

struct HeavyLight {
  int root = 0, n = 0;
  vector<int> parent, deep, hson, top, sz, dfn;
  HeavyLight(vector<vector<int>> &g, int _root)
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
      path[front].push_back({dfn[top[y]], dfn[y] + 1});
      y = parent[top[y]];
    }
    if (deep[x] > deep[y]) swap(x, y), front = !front;

    path[front].push_back({dfn[x], dfn[y] + 1});
    reverse(path[1].begin(), path[1].end());
    for (const auto &[left, right] : path[1]) path[0].push_back({right, left});
    return path[0];
  }

  Node query_seg(int u, int v, const SegTree &seg) const {
    auto node = Node();
    for (const auto &[left, right] : get_dfn_path(u, v)) {
      if (left > right) {
        node = pull(node, rev(seg.query(right, left)));
      } else {
        node = pull(node, seg.query(left, right));
      }
    }
    return node;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }

    const auto hld = HeavyLight(g, 0);

    auto seg = SegTree(n);
    for (int i = 0; i < n; i++) seg.t[n + hld.dfn[i]] = Node(a[i], hld.deep[i]);
    for (int i = n - 1; i > 0; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);

    int q;
    cin >> q;
    while (q--) {
      int u, v;
      cin >> u >> v, u--, v--;
      const auto node = hld.query_seg(u, v, seg);
      int addon = 0;
      map<int, int> events;
      for (auto &[x, y] : node.info) {
        if (x != -1) events[x] += 1, events[y + 1] -= 1, addon++;
      }
      int cur = 0, res = 0;
      for (auto &[x, y] : events) {
        cur += y;
        res = max(res, cur);
      }
      cout << res + addon << " ";
    }
    cout << "\n";
  }
}
