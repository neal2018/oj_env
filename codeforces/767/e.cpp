#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct Node {
  ll maxi = -1e18, mini = 1e18;
  int maxi_id = -1, mini_id = -1, is_on = -1;
};

Node pull(const Node &a, const Node &b) {
  Node c;
  if (a.is_on == 0 && b.is_on == 0) return c;
  if (a.is_on == 0) {
    c = b, c.is_on = -1;
    return c;
  }
  if (b.is_on == 0) {
    c = a, c.is_on = -1;
    return c;
  }
  for (auto &x : {a, b}) {
    if (x.maxi > c.maxi) c.maxi = x.maxi, c.maxi_id = x.maxi_id;
    if (x.mini < c.mini) c.mini = x.mini, c.mini_id = x.mini_id;
  }
  return c;
}

struct SegTree {
  ll n, h = 0;
  vector<Node> t, full;
  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(n * 2), full(n * 2) {}
  void apply(ll x, int v) {
    if (v == 0) {
      t[x] = Node();
    } else {
      t[x] = full[x];
    }
    t[x].is_on = v;
  }
  void build(ll l) {
    for (l = (l + n) / 2; l > 0; l /= 2) {
      if (t[l].is_on == -1) {
        t[l] = pull(t[l * 2], t[l * 2 + 1]);
      } else {
        apply(l, t[l].is_on);
      }
    }
  }
  void push(ll l) {
    l += n;
    for (ll s = h; s > 0; s--) {
      ll i = l >> s;
      if (t[i].is_on != -1) {
        apply(2 * i, t[i].is_on);
        apply(2 * i + 1, t[i].is_on);
      }
      t[i].is_on = -1;
    }
  }
  void modify(ll l, ll r, int v) {
    push(l), push(r - 1);
    ll l0 = l, r0 = r;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    build(l0), build(r0 - 1);
  }
  Node query(ll l, ll r) {
    push(l), push(r - 1);
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
  int m, q;
  cin >> m >> q;
  int n = 2 * m - 1;
  vector<array<int, 3>> edges(m - 1);
  for (auto &[w, u, v] : edges) {
    cin >> u >> v >> w, u--, v--;
  }
  sort(edges.begin(), edges.end());
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
  auto merge = [&](int x, int y) { p[find(x)] = find(y); };
  vector<vector<int>> g(n);
  vector<int> val(m);
  val.reserve(n);
  for (auto [w, u, v] : edges) {
    u = find(u), v = find(v);
    if (u == v) continue;
    val.push_back(w);
    int node = (int)val.size() - 1;
    g[node].push_back(u), g[node].push_back(v);
    merge(u, node), merge(v, node);
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
  vector<int> dfn(n, -1);
  int cur = 0;
  function<void(int)> get_order = [&](int node) {
    for (auto &ne : g[node]) {
      if (ne == parent[node]) continue;
      get_order(ne);
      if (dfn[node] == -1) dfn[node] = cur++;
    }
    if (dfn[node] == -1) dfn[node] = cur++;
  };
  get_order(n - 1);
  SegTree seg(m);
  for (int i = 0; i < m; i++) seg.t[m + i] = {dfn[i], dfn[i], i, i, 0};
  // for (int i = m - 1; i >= 0; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
  for (int i = 0; i < m; i++) seg.full[m + i] = {dfn[i], dfn[i], i, i, 1};
  for (int i = m - 1; i > 0; i--) seg.full[i] = pull(seg.full[i * 2], seg.full[i * 2 + 1]);
  while (q--) {
    int t, l, r, x;
    cin >> t;
    if (t == 1) {
      cin >> l >> r, l--;
      seg.modify(l, r, 1);
    } else if (t == 2) {
      cin >> l >> r, l--;
      seg.modify(l, r, 0);
    } else {
      cin >> x, x--;
      auto node = seg.query(0, m);
      if (node.maxi_id == -1) {
        cout << "-1\n";
      } else if (node.maxi_id == x && node.mini_id == x) {
        cout << "-1\n";
      } else {
        int left = val[lca(x, node.mini_id)];
        int right = val[lca(x, node.maxi_id)];
        cout << max(left, right) << '\n';
      }
    }
  }
}
