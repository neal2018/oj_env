#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> b >> a, a--, b--;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    vector<int> stk, is_ring(n);
    {
      vector<int> seen(n);
      int found = 0;
      function<void(int, int)> dfs = [&](int node, int fa) {
        if (found) return;
        stk.push_back(node);
        seen[node] = 1;
        for (auto& ne : g[node]) {
          if (ne == fa) continue;
          if (found) return;
          if (seen[ne]) {
            int index = int(stk.size()) - 1;
            while (true) {
              is_ring[stk[index]] = 1;
              index--;
              if (stk[index] == ne) break;
            }
            is_ring[ne] = 1;
            found = 1;
          } else {
            dfs(ne, node);
          }
        }
        stk.pop_back();
      };
      dfs(0, -1);
    }
    if (is_ring[a]) {
      if (a != b) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      continue;
    }
    auto get_dist_pos_on_ring = [&](int x) {
      int res = n, pos = -1;
      int cur = -1, found = 0;
      function<void(int, int)> dfs = [&](int node, int fa) {
        if (found) return;
        cur++;
        if (is_ring[node]) {
          res = cur, pos = node, found = 1;
          return;
        }
        for (auto& ne : g[node]) {
          if (ne == fa) continue;
          if (found) return;
          dfs(ne, node);
        }
        cur--;
      };
      dfs(x, -1);
      return pair{res, pos};
    };

    auto [a_dist, a_on_ring] = get_dist_pos_on_ring(a);
    auto [b_dist, b_on_ring] = get_dist_pos_on_ring(b);

    auto b_to_a_on_ring = [&](int t) {
      int res = n;
      vector<int> seen(n);
      int cur = -1;
      function<void(int)> dfs = [&](int node) {
        seen[node] = 1;
        cur++;
        if (node == t) {
          res = min(res, cur);
          cur--;
          return;
        }
        for (auto& ne : g[node]) {
          if (seen[ne] && ne != t) continue;
          dfs(ne);
        }
        cur--;
      };
      dfs(b);
      return res;
    }(a_on_ring);

    if (is_ring[b] || (a_on_ring != b_on_ring)) {
      if (a_dist < b_to_a_on_ring) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      continue;
    }
    int a_to_lca = 0, b_to_lca = 0;
    function<pair<int, int>(int, int)> dfs = [&](int node, int fa) -> pair<int, int> {
      vector<pair<int, int>> res;
      if (node == a) res = {{0, 0}};
      if (node == b) res = {{1, 0}};
      for (auto& ne : g[node]) {
        if (ne == fa || is_ring[ne]) continue;
        auto [token, dist] = dfs(ne, node);
        if (token != -1) res.push_back({token, dist + 1});
      }
      if (res.size() == 2) {
        sort(res.begin(), res.end());
        a_to_lca = res[0].second;
        b_to_lca = res[1].second;
      } else if (res.size() == 1) {
        return res[0];
      }
      return {-1, 0};
    };

    dfs(a_on_ring, -1);
    if (a_to_lca < b_to_lca) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
