#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  set<pair<int, int>> edges;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
    edges.insert({v, u}), edges.insert({u, v});
  }
  vector<ll> p(n);
  iota(p.begin(), p.end(), 0);
  function<ll(ll)> find = [&](ll x) { return x == p[x] ? x : (p[x] = find(p[x])); };
  auto merge = [&](ll x, ll y) { p[find(x)] = find(y); };
  {
    set<int> unseen;
    for (int i = 0; i < n; ++i) unseen.insert(i);
    vector<int> seen(n);
    for (int i = 0; i < n; ++i) {
      if (!seen[i]) {
        vector<int> q{i}, nq;
        seen[i] = 1;
        unseen.erase(i);
        for (; q.size(); swap(q, nq), nq.clear()) {
          for (auto& node : q) {
            set<int> need;
            for (auto y : g[node]) {
              if (!seen[y]) unseen.erase(y), need.insert(y);
            }
            for (auto ne : unseen) {
              seen[ne] = 1;
              merge(node, ne);
              nq.push_back(ne);
            }
            unseen = need;
          }
        }
      }
    }
  }
  vector<ll> belong(n);
  for (int i = 0; i < n; i++) belong[i] = find(i);
  auto compress = belong;
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  if (compress.size() != 3) {
    cout << "-1";
    return 0;
  }
  vector<vector<int>> part(3);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (belong[i] == compress[j]) part[j].push_back(i);
    }
  }
  for (auto& [u, v] : edges) {
    if (find(u) == find(v)) {
      cout << "-1";
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (belong[i] == compress[j]) {
        cout << j + 1 << " ";
      }
    }
  }
  cout << "\n";
}
