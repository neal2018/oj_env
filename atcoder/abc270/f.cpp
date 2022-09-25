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
  const int AIR = n, SEA = n + 1;
  auto solve = [&] {
    sort(edges.begin(), edges.end());
    auto uf = UnionFind(n + 2);
    ll res = 0;
    for (auto& [c, x, y] : edges) {
      if (uf.find(x) == uf.find(y)) continue;
      uf.merge(x, y);
      res += c;
    }
    for (int i = 0; i < n; i++) {
      if (uf.find(i) != uf.find(0)) {
        return inf;
      }
    }
    return res;
  };
  ll res = solve();
  // cout << solve() << "\n";

  for (int i = 0; i < n; i++) edges.push_back({air[i], i, AIR});
  auto save = edges;
  res = min(res, solve());
  // cout << solve() << "\n";
  edges = save;
  for (int i = 0; i < n; i++) edges.pop_back();
  for (int i = 0; i < n; i++) edges.push_back({sea[i], i, SEA});
  res = min(res, solve());
  // cout << solve() << "\n";
  for (int i = 0; i < n; i++) edges.push_back({air[i], i, AIR});
  res = min(res, solve());
  // cout << solve() << "\n";

  cout << res << "\n";
}
