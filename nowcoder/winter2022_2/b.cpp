#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  ll all = accumulate(a.begin(), a.end(), 0ll);
  vector<int> order(n), seen(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int x, int y) { return a[x] > a[y]; });
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
  auto merge = [&](int x, int y) { p[find(x)] = find(y); };
  ll res = 0;
  for (auto i : order) {
    seen[i] = 1;
    for (auto& ne : g[i]) {
      if (seen[ne] && find(i) != find(ne)) {
        res += a[find(ne)] - a[i];
        merge(ne, i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (find(i) == i) res += a[i];
  }
  cout << res << "\n";
}