#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
  void merge(int x, int y) { p[find(x)] = find(y); }
};

constexpr ll inf = 1e18;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> air(n), sea(n);
  for (auto& x : air) cin >> x;
  for (auto& x : sea) cin >> x;
  vector<array<int, 3>> edges(m);
  for (auto& [c, x, y] : edges) cin >> x >> y >> c, x--, y--;

  auto solve = [&](auto& candidates) {
    sort(candidates.begin(), candidates.end());
    auto uf = UnionFind(n + 2);
    ll res = 0;
    for (auto& [c, x, y] : candidates) {
      if (uf.find(x) == uf.find(y)) continue;
      uf.merge(x, y);
      res += c;
    }
    for (int i = 0; i < n; i++) {
      if (uf.find(i) != uf.find(0)) return inf;
    }
    return res;
  };

  const int AIR = n, SEA = n + 1;
  ll res = inf;
  for (int need_air : {0, 1}) {
    for (int need_sea : {0, 1}) {
      auto temp = edges;
      for (int i = 0; i < n; i++) {
        if (need_air) temp.push_back({air[i], i, AIR});
        if (need_sea) temp.push_back({sea[i], i, SEA});
      }
      res = min(res, solve(temp));
    }
  }
  cout << res << "\n";
}
