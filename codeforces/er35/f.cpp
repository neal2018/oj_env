#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    vector<ll> parent(n), deep(n, -1), mark_odd(n), mark_even(n), color(n);
    ll odd = 0, edge = -1;  // [parent[node], node]
    function<void(ll, ll, ll, ll)> dfs = [&](ll node, ll fa, ll dep, ll c) {
      deep[node] = dep, parent[node] = fa, color[node] = c;
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        if (deep[ne] == -1) {
          dfs(ne, node, dep + 1, !c);
        } else if (deep[ne] < deep[node]) {
          ll len = deep[node] - deep[ne] + 1;
          if (len & 1) {
            mark_odd[node]++, mark_odd[ne]--;
            odd++, edge = node;
          } else {
            mark_even[node]++, mark_even[ne]--;
          }
        }
      }
    };
    dfs(0, -1, 0, 0);
    if (odd > 1) {
      edge = -1;
      function<void(ll)> dfs2 = [&](ll node) {
        for (auto& ne : g[node]) {
          if (parent[ne] != node) continue;
          dfs2(ne);
          mark_odd[node] += mark_odd[ne], mark_even[node] += mark_even[ne];
        }
        if (mark_odd[node] == odd && mark_even[node] == 0) {
          edge = node;
        }
      };
      dfs2(0);
      if (edge != -1) {
        function<void(ll)> dfs3 = [&](ll node) {
          color[node] = !color[node];
          for (auto& ne : g[node]) {
            if (parent[ne] != node) continue;
            dfs3(ne);
          }
        };
        dfs3(edge);
      }
    }
    if (edge != -1 && color[edge] == 0) {
      for (auto& x : color) x = !x;
    }
    if (odd == 0 || edge != -1) {
      cout << "YES\n";
      for (auto& x : color) cout << x;
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }
}
