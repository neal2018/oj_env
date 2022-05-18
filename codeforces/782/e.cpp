#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr int SZ = 30;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edge(m);
  for (auto& [a, b, w] : edge) cin >> a >> b >> w, a--, b--;
  vector<vector<int>> dsu(SZ, vector<int>(n));
  function<int(int, vector<int>&)> find = [&](int x, vector<int>& p) {
    return x == p[x] ? x : (p[x] = find(p[x], p));
  };
  auto merge = [&](int x, int y, vector<int>& p) { p[find(x, p)] = find(y, p); };
  for (int i = 0; i < SZ; i++) {
    auto& p = dsu[i];
    iota(p.begin(), p.end(), 0);
    for (auto& [u, v, w] : edge) {
      if (w & (1 << i)) merge(u, v, p);
    }
  }
  vector<int> good(n);
  vector<int> potential(n);
  for (auto& [u, v, w] : edge) {
    if ((w % 2 == 0)) potential[u] = 1, potential[v] = 1;
  }
  for (int i = 1; i < SZ; i++) {
    vector<int> p(n), cur(n);
    iota(p.begin(), p.end(), 0);
    for (auto& [u, v, w] : edge) {
      if ((w & 1) && (w & (1 << i))) merge(u, v, p);
    }
    for (int t = 0; t < n; t++) {
      if (potential[t]) cur[find(t, p)] = 1;
    }
    for (int t = 0; t < n; t++) {
      good[t] |= cur[find(t, p)];
    }
  }
  auto answer = [&](int u, int v) {
    for (auto& p : dsu) {
      if (find(u, p) == find(v, p)) return 0;
    }
    return good[u] ? 1 : 2;
  };
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v, u--, v--;
    cout << answer(u, v) << "\n";
  }
}
