#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

  // Node query_seg(int u, int v, const SegTree &seg) const {
  //   auto node = Node();
  //   for (const auto &[left, right] : get_dfn_path(u, v)) {
  //     if (left > right) {
  //       node = pull(node, rev(seg.query(right, left)));
  //     } else {
  //       node = pull(node, seg.query(left, right));
  //     }
  //   }
  //   return node;
  // }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> is_red(n);
    for (int i = 0, x; i < m; i++) {
      cin >> x, x--, is_red[x] = 1;
    }
    vector<vector<array<int, 2>>> g(n);
    vector<vector<int>> g_for_hld(n);
    for (int i = 0, u, v, w; i < n - 1; i++) {
      cin >> u >> v >> w, u--, v--;
      g[u].push_back({v, w}), g[v].push_back({u, w});
      g_for_hld[u].push_back(v), g_for_hld[v].push_back(u);
    }

    vector<ll> cost(n);
    vector<int> last_red(n);

    function<void(int, int)> get_cost = [&](int node, int fa) {
      for (auto &[ne, w] : g[node]) {
        if (ne == fa) continue;
        if (!is_red[ne]) {
          cost[ne] = cost[node] + w;
          last_red[ne] = last_red[node];
        } else {
          last_red[ne] = ne;
        }
        get_cost(ne, node);
      }
    };
    get_cost(0, -1);

    auto hld = HeavyLight(g_for_hld, 0);

    while (q--) {
      int k;
      cin >> k;
      vector<array<ll, 2>> a(k);
      for (auto &[c, x] : a) {
        cin >> x, x--;
        c = cost[x];
      }
      sort(a.begin(), a.end(), greater<>());
      if (a.size() == 1) {
        cout << "0\n";
        continue;
      }
      ll res = a[1][0];
      ll node = -1, top = -1;
      for (int i = 0; i < k; i++) {
        if (node == -1) {
          node = a[i][1];
          top = last_red[a[i][1]];
        } else if (last_red[a[i][1]] != top) {
          break;
        } else {
          node = hld.lca(int(node), int(a[i][1]));
        }

        const auto minus = cost[node];
        auto cur = a[0][0] - minus;
        if (i != k - 1) {
          cur = max(cur, a[i + 1][0]);
        }
        res = min(res, cur);
      }
      cout << res << "\n";
    }
  }
}
