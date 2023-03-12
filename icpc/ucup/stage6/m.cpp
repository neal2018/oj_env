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
  int n;
  cin >> n;
  UnionFind uf(n);
  for (int _ = 0; _ < n; _++) {
    int p, q;
    cin >> p >> q;
    if (uf.find(p) != uf.find(q)) {
      uf.merge(p, q);
      cout << "N\n";
    } else {
      cout << "Y\n";
    }
  }
}
