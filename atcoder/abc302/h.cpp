#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> p;
  vector<int> has_ring;
  vector<pair<int&, int>> history;
  UnionFind(int n) : p(n, -1), has_ring(n) {}
  int find(int x) { return p[x] < 0 ? x : find(p[x]); }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
      if (has_ring[x]) return false;
      change(has_ring[x], 1);
      return true;
    }
    if (has_ring[x] && has_ring[y]) return false;
    int sz_x = -p[x], sz_y = -p[y];
    if (sz_x < sz_y) swap(x, y), swap(sz_x, sz_y);
    change(p[x], -(sz_x + sz_y));
    change(has_ring[x], has_ring[x] + has_ring[y]);
    change(p[y], x);
    return true;
  }
  void change(int& x, int y) {
    history.push_back({x, x});
    x = y;
  }
  void rollback(size_t pos) {
    while (history.size() > pos) {
      auto [x_ref, x] = history.back();
      history.pop_back();
      x_ref = x;
    }
  };
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  for (auto& [x, y] : a) cin >> x >> y, x--, y--;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  UnionFind uf(n);
  vector<int> res(n);
  function<void(int, int)> dfs = [&](int node, int fa) {
    auto mark = uf.history.size();
    res[node] = fa == -1 ? 0 : res[fa];
    res[node] += uf.merge(a[node][0], a[node][1]);
    for (auto& ne : g[node]) {
      if (fa == ne) continue;
      dfs(ne, node);
    }
    uf.rollback(mark);
  };
  dfs(0, -1);
  res.erase(res.begin());
  for (auto& x : res) cout << x << " ";
}
