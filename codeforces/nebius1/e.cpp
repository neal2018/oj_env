#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
    mat[u][v] = mat[v][u] = 1;
  }
  // simple cycle iteration
  vector from(1 << n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) from[1 << i][i] = i;

  for (int mask = 1; mask < (1 << n); mask++) {
    int start = [&] {
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) return i;
      }
      return -1;
    }();
    for (int cur = start; cur < n; cur++) {
      if (from[mask][cur] == -1) continue;
      for (int ne = start + 1; ne < n; ne++) {
        if (mat[cur][ne] && (mask & (1 << ne)) == 0) {
          from[mask | (1 << ne)][ne] = cur;
        }
      }
      if (cur != start && mat[start][cur]) {
        int seen = 0;
        vector<int> res(n);
        for (int i = start; i < n; i++) {
          if (mask & (1 << i)) {
            for (auto& ne : g[i]) seen |= 1 << ne, res[ne] = i;
            seen |= 1 << i;
          }
        }
        if (seen == (1 << n) - 1) {
          cout << "Yes\n";
          res[start] = cur;
          int cur_mask = mask;
          int cur_node = cur;
          while (true) {
            int prev_mask = cur_mask ^ (1 << cur_node);
            if (prev_mask == 0) break;
            res[cur_node] = from[cur_mask][cur_node];
            cur_node = res[cur_node], cur_mask = prev_mask;
          }
          for (auto& x : res) cout << x + 1 << " ";
          cout << "\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";
}
