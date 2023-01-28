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
  UnionFind uf(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    uf.merge(u, v);
  }
  vector<int> bad;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (x) bad.push_back(i);
  }
  vector<ll> sz(n);
  for (int i = 0; i < n; i++) sz[uf.find(i)]++;
  ll res = 0;
  if (bad.size() == 0) {
    for (auto& x : sz) res += x * x;
  } else {
    if (all_of(bad.begin(), bad.end(), [&](int x) { return uf.find(x) == uf.find(bad[0]); })) {
      res = sz[uf.find(bad[0])] * sz[uf.find(bad[0])];
    }
  }
  cout << res << "\n";
}