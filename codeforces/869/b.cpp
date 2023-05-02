#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
      deg[u]++, deg[v]++;
    }
    int cnt = 0, now = 0;
    vector<ll> dfn(n, -1), low(n), belong(n, -1);
    {
      vector<ll> stk;
      function<void(ll, ll)> tarjan = [&](ll node, ll fa) {
        dfn[node] = low[node] = now++, stk.push_back(node);
        for (auto& ne : g[node]) {
          if (ne == fa) continue;  // remove if directed
          if (dfn[ne] == -1) {
            tarjan(ne, node);
            low[node] = min(low[node], low[ne]);
          } else if (belong[ne] == -1) {
            low[node] = min(low[node], dfn[ne]);
          }
        }
        if (dfn[node] == low[node]) {
          while (true) {
            auto v = stk.back();
            belong[v] = cnt;
            stk.pop_back();
            if (v == node) break;
          }
          ++cnt;
        }
      };
      for (int i = 0; i < n; i++) {
        assert(stk.size() == 0);
        if (dfn[i] == -1) tarjan(i, -1);
      }
    }
    vector<int> freq(cnt);
    for (auto& x : belong) freq[x]++;
    int good = 0;
    [&] {
      for (int i = 0; i < n; i++) {
        if (deg[i] >= 4 && freq[belong[i]] >= 3) {
          vector<int> stk, seen(n);
          vector<int> path;
          function<void(int, int)> dfs = [&](int node, int fa) {
            if (good) return;
            if (node == i && stk.size() > 0) {
              path = stk;
              vector<array<int, 2>> res;
              for (int ii = 0; ii < path.size(); ii++) {
                res.push_back({path[ii], path[(ii + 1) % path.size()]});
              }
              set st(path.begin(), path.end());
              int need = 0;
              for (auto& ne : g[i]) {
                if (st.count(ne) == 0) {
                  res.push_back({i, ne});
                  need++;
                }
                if (need == 2) break;
              }
              if (need == 2) {
                cout << "YES\n";
                cout << res.size() << "\n";
                for (auto& [x, y] : res) cout << x + 1 << " " << y + 1 << "\n";
                good = 1;
                return;
              }
            }
            if (seen[node]) return;
            seen[node] = 1;
            stk.push_back(node);
            for (auto& ne : g[node]) {
              if (ne == fa) continue;
              dfs(ne, node);
            }
            stk.pop_back();
          };
          dfs(i, -1);
        }
      }
      if (!good) cout << "NO\n";
    }();
  }
}
