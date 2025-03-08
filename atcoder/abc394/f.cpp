#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct UnionFind {
  std::vector<int> p;
  UnionFind(int n) : p(n) { std::iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
  void merge(int x, int y) { p[find(x)] = find(y); }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    std::cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  auto uf = UnionFind(n);

  for(int i=0;i<n;i++) {
    for (auto v : g[i]) {
      if (g[i].size() <= 4 || g[v].size() <=4) {
        uf.merge(i, v);
      }
    }
  }
  auto sz = std::vector<int> (n);
  for (int i=0;i<n;i++) {
    sz[uf.find(i)]++;
  }
  int res = -1;

  
}
