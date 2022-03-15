#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n, vector<ll>(n, inf));
  vector<vector<ll>> dist(n, vector<ll>(n, inf));
  vector<vector<ll>> can(n, vector<ll>(n, 0));
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w, u--, v--;
    g[u][v] = w, g[v][u] = w;
    dist[u][v] = w, dist[v][u] = w;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] + dist[k][j] <= dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          can[i][j] = 1;
        }
      }
    }
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (g[i][j] != inf && can[i][j]) {
        res++;
      }
    }
  }
  cout << res << "\n";
}
