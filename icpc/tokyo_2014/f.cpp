#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 502;
int adj[MX][MX];
int dist[MX], from[MX];
int n, m;
const int INF = 1e9;
vector<pair<int, int>> check;

int prim(bool first) {
  for (int i = 0; i < n; i++) dist[i] = INF;
  dist[0] = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int best = INF, nextv = -1;
    for (int j = 0; j < n; j++) {
      if (dist[j] != -1 && dist[j] < best) {
        best = dist[j];
        nextv = j;
      }
    }
    if (nextv == -1) return INF;
    if (best > 0 && first) check.push_back({from[nextv], nextv});
    for (int j = 0; j < n; j++) {
      if (adj[nextv][j] == 0) continue;
      if (adj[nextv][j] < dist[j]) {
        dist[j] = adj[nextv][j];
        from[j] = nextv;
      }
    }
    ans += dist[nextv];
    dist[nextv] = -1;
  }
  return ans;
}

int main() {
  cin >> n >> m;

  memset(adj, 0, sizeof adj);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    adj[u][v] = w;
    adj[v][u] = w;
  }

  int ans1 = 0, ans2 = 0, tweight = prim(true);
  for (auto [u, v] : check) {
    int tmp = adj[u][v];
    adj[u][v] = 0;
    adj[v][u] = 0;
    if (prim(false) != tweight) {
      ans1++;
      ans2 += tmp;
    }
    adj[u][v] = tmp;
    adj[v][u] = tmp;
  }

  cout << ans1 << ' ' << ans2 << '\n';
}
