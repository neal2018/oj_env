#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
const char nl = '\n';

int main() {
  int n, q;
  cin >> n >> q;
  int root = 0;
  vector<vector<int>> graph(n);
  vi parent(n), deep(n), hson(n, -1), top(n), sz(n);
  function<int(int, int, int)> dfs = [&](int node, int fa, int dep) {
    deep[node] = dep, sz[node] = 1, parent[node] = fa;
    for(auto & ne : graph[node]) {
      if (ne == fa) continue;
      sz[node] += dfs(ne, node, dep+1);
      if(hson[node] == -1 || sz[ne] > sz[hson[node]]) hson[node] = ne; 
    }
    return sz[node];
  };
  function<void(int, int)> dfs2 = [&](int node, int t) {
    top[node] = t;
    if(hson[node] == -1) return;
    dfs2(hson[node], t);
    for (auto&ne: graph[node]) {
      if(ne == parent[node] || ne == hson[node]) continue;
      dfs2(ne, ne);
    }
  };

  function<int(int, int)> lca = [&](int x, int y) {
    while(top[x] != top[y]) {
      if (deep[top[x]] < deep[top[y]]) swap(x, y);
      x = parent[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
  };
  forn(i, n-1) {
    int u, v;
    cin >> u >> v; u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(root, -1, 1), dfs2(root, root);

  forn(i, q) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    int common = lca(u, v);
    ll path = (deep[u] - deep[common]) + (deep[v] - deep[common]) + 1;  
    ll ans = (path) * (path+1)/2;
    ans += n - path;
    cout << ans << nl;
  }
  
}

