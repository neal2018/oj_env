#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct CentroidDecomposition {
  int n;
  vector<int> seen, sz, parent;
  CentroidDecomposition(const vector<vector<int>>& g)
      : n(int(g.size())), seen(n), sz(n), parent(n) {
    function<int(int, int)> get_size = [&](int node, int fa) {
      sz[node] = 1;
      for (auto& ne : g[node]) {
        if (ne != fa && !seen[ne]) sz[node] += get_size(ne, node);
      }
      return sz[node];
    };
    function<int(int, int, int)> find_centroid = [&](int node, int fa, int total) {
      for (auto& ne : g[node]) {
        if (ne != fa && !seen[ne] && sz[ne] * 2 > total) return find_centroid(ne, node, total);
      }
      return node;
    };
    function<void(int, int)> solve = [&](int node, int fa) {
      auto c = find_centroid(node, -1, get_size(node, -1));
      parent[c] = fa, seen[c] = 1;
      for (auto& ne : g[c]) {
        if (!seen[ne]) solve(ne, c);
      }
    };
    solve(0, -1);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  auto cd = CentroidDecomposition(g);
  for (auto& x : cd.parent) {
    cout << (x == -1 ? -1 : (x + 1)) << " ";
  }
  cout << "\n";
}
