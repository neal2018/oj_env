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
  vector<int> deg(n);
  UnionFind uf(n);
  cout << ([&] {
    int one_cnt = 0;
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v, u--, v--;
      deg[u]++, deg[v]++;
      if (uf.find(u) == uf.find(v)) return false;
      uf.merge(u, v);
    }
    for (auto& x : deg) {
      if (x == 1) {
        one_cnt++;
      } else if (x != 2) {
        return false;
      }
    }
    return one_cnt == 2;
  }()
               ? "Yes\n"
               : "No\n");
}