#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m, s;
  cin >> n >> m >> s, s--;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    if (v == s) continue;
    g[u].push_back(v);
  }
  vector<int> color(n, -1), parent(n, -1);
  vector<vector<int>> res;
  int another = -1, target = -1;
  for (auto& start : g[s]) {
    vector<int> stk{s, start};
    int found = 0;
    function<void(int, int)> dfs = [&](int node, int fa) {
      if (found) return;
      if (node == s || color[node] == start) return;
      if (color[node] != -1) {
        // res.push_back(stk);
        found = 1;
        target = node;
        another = color[node];
        assert(another != start);
        vector<int> path{target, fa};
        int cur = fa;
        while (cur != s) {
          cur = parent[cur];
          path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        res.push_back(path);
        {
          vector<int> path{target};
          int cur = target;
          while (cur != s) {
            cur = parent[cur];
            path.push_back(cur);
          }
          reverse(path.begin(), path.end());
          res.push_back(path);
          cout << "Possible\n";
          for (auto& v : res) {
            cout << v.size() << " ";
            for (auto& x : v) cout << x + 1 << " ";
            cout << "\n";
          }
        }
        exit(0);
        return;
      }
      color[node] = start;
      parent[node] = fa;
      for (auto& ne : g[node]) {
        if (ne == s || color[ne] == start) continue;
        stk.push_back(ne);
        dfs(ne, node);
        stk.pop_back();
      }
    };
    dfs(start, s);
  }
  cout << "Impossible\n";
}