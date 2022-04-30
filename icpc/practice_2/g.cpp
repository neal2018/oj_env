#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using vi = vector<int>;

int cnt = 0;

void enumerate_triangles(vector<pair<int, int>>& edges) {
  int n = 0;
  for(auto[u,v]:edges) n = max({n, u+1, v+1});
  vi deg(n);
  vi g[n];
  for(auto [u,v] : edges) {
    deg[u]++;
    deg[v]++;
  }
  for(auto [u,v] : edges) {
    if(u==v) continue;
    if(deg[u] > deg[v] || (deg[u] == deg[v] && u>v)) swap(u,v);
    g[u].push_back(v);
  }
  vi flag(n);

  for(int i = 0; i < n; i++) {
    for(int v : g[i]) flag[v]=1;
    for(int v : g[i]) for(int u : g[v]) {
      if(flag[u]) cnt++;
    }
    for(int v : g[i]) flag[v] = 0;
  }

}

void solve() {

  int n;
  cin >> n;
  vector<ll> degree(n+1, 0);
  vector<pair<int, int>> edges;
  for(int i = 0; i < n-1; i++) {
    int u,v;
    cin >> u >> v;
    if(u > v) swap(u, v);
    edges.push_back({u,v});
  }
  sort(edges.begin(), edges.end());
  edges.erase(unique(edges.begin(), edges.end()), edges.end());

  for(auto [u,v] : edges) {
    degree[u]++;
    degree[v]++;
  }
  ll ans = 0;
  for(ll z:  degree) {
    ans += z * (z-1);
  }
  enumerate_triangles(edges);
  ans -= 6 * cnt;
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  t = 1;
  while(t--) {
    solve();
  }

}