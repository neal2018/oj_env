#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
  void merge(int x, int y) { p[find(x)] = find(y); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (auto& [u, v] : edges) cin >> u >> v, u--, v--;
  auto uf = UnionFind(n);
  vector<vector<int>> tree(n), query(n);
  for (auto& [u, v] : edges) {
    if (uf.find(u) != uf.find(v)) {
      uf.merge(u, v);
      tree[u].push_back(v), tree[v].push_back(u);
    } else {
      query[u].push_back(v), query[v].push_back(u);
    }
  }
  vector<int> addon(n), nex(n, -1);
  function<void(int, int)> dfs = [&](int node, int fa) {
    for (auto& v : query[node]) {
      if (nex[v] != -1) {
        addon[0]++, addon[nex[v]]--;
      } else {
        addon[v]++;
      }
    }
    for (auto& ne : tree[node]) {
      if (ne == fa) continue;
      nex[node] = ne;
      dfs(ne, node);
    }
    nex[node] = -1;
  };
  dfs(0, -1);
  string res(n, '0');
  function<void(int, int)> collect = [&](int node, int fa) {
    if (addon[node] == m - (n - 1)) {
      res[node] = '1';
    }
    for (auto& ne : tree[node]) {
      if (ne == fa) continue;
      addon[ne] += addon[node];
      collect(ne, node);
    }
  };
  collect(0, -1);
  cout << res << "\n";
}
