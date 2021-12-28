#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n;
  vector<int> t(n), res, seen(n), q, ok(n);
  vector<vector<pair<int, int>>> g(n);
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
  auto merge = [&](int x, int y) { p[find(x)] = find(y); };
  for (auto& x : t) cin >> x, x--;
  cin >> m;
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b, a--, b--;
    g[a].push_back({b, i}), g[b].push_back({a, i});
    merge(a, b);
  }
  for (int i = 0; i < n; i++) {
    if (find(t[i]) != find(i)) return cout << -1 << '\n', 0;
  }
  function<void(int)> topo = [&](int node) {
    seen[node] = 1;
    q.push_back(node);
    for (auto& [ne, i] : g[node]) {
      if (!seen[ne]) topo(ne);
    }
  };
  for (int i = 0; i < n; i++)
    if (!seen[i]) topo(i);
  reverse(q.begin(), q.end());
  function<bool(int, int)> dfs = [&](int node, int target) {
    if (t[node] == target) return true;
    seen[node] = 1;
    for (auto& [ne, i] : g[node]) {
      if (!seen[ne] && dfs(ne, target)) {
        res.push_back(i);
        swap(t[node], t[ne]);
        return true;
      }
    }
    return false;
  };
  for (auto& node : q) {
    seen = ok;
    dfs(node, node);
    ok[node] = 1;
  }
  cout << res.size() << "\n";
  for (auto& x : res) cout << x + 1 << " ";
  cout << "\n";
}
