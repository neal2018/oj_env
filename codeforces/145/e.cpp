#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto edmond(int n, int root, vector<array<int, 3>> edges) {
  constexpr int inf = 1e9;
  int m = int(edges.size());
  int res = 0, max_edge_id = m - 1;
  vector<int> used(m), to_delete(m), to_add(m), edge_id(m);
  iota(edge_id.begin(), edge_id.end(), 0);
  while (true) {
    vector<int> pre(n, -1), seen(n, -1), circle(n, -1), in_edge(n, inf), choose(n);
    in_edge[root] = 0;
    for (int i = 0; i < m; i++) {
      auto& [u, v, w] = edges[i];
      if (u != v && w < in_edge[v]) {
        pre[v] = u, in_edge[v] = w, choose[v] = edge_id[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (i != root && in_edge[i] == inf) return pair{-1, vector<int>()};
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      res += in_edge[i];
      if (i != root) used[choose[i]]++;
      int v = i;
      for (; seen[v] != i && circle[v] == -1 && v != root; v = pre[v]) seen[v] = i;
      if (v != root && circle[v] == -1) {
        for (; circle[v] != cnt; v = pre[v]) circle[v] = cnt;
        cnt++;
      }
    }
    if (cnt == 0) break;
    for (int i = 0; i < n; i++) {
      if (circle[i] == -1) circle[i] = cnt++;
    }
    for (int i = 0; i < m; i++) {
      auto& [u, v, w] = edges[i];
      int o_v = v;
      u = circle[u], v = circle[v];
      if (u != v) {
        w -= in_edge[o_v];
        used.emplace_back(), to_delete.push_back(choose[o_v]), to_add.push_back(edge_id[i]);
        edge_id[i] = ++max_edge_id;
      }
    }
    n = cnt, root = circle[root];
  }
  for (int i = max_edge_id; i >= m; i--) {
    if (used[i]) used[to_delete[i]]--, used[to_add[i]]++;
  }
  return pair{res, vector<int>(used.begin(), used.begin() + m)};
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges(m);
  for (auto& [u, v, w] : edges) cin >> u >> v >> w, u--, v--;
  auto&& [res, used] = edmond(n, 0, edges);
  cout << res << "\n";
  if (res == -1 || res == 0) return 0;
  for (int i = 0; i < m; i++) {
    if (used[i] && edges[i][2]) cout << i + 1 << " ";
  }
  cout << "\n";
}
