#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> color(n, 1);
  int red = n, blue = 0;
  int find = 0;
  vector<int> stk;
  vector<int> seen(n);
  function<void(int, int)> dfs = [&](int node, int fa) {
    seen[node] = 1;
    color[node] = 0;
    stk.push_back(node);
    red--;
    if (red == blue) {
      find = 1;
      return;
    }
    for (auto& ne : g[node]) {
      if (ne == fa || seen[ne]) continue;
      dfs(ne, node);
      if (find) return;
    }
    stk.pop_back();
    color[node] = 2;
    blue++;
    if (red == blue) {
      find = 1;
      return;
    }
  };
  dfs(0, -1);
  cout << stk.size() << " " << red << "\n";
  for (auto& x : stk) cout << x + 1 << " ";
  cout << "\n";
  for (int i = 0; i < n; i++) {
    if (color[i] == 1) cout << i + 1 << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    if (color[i] == 2) cout << i + 1 << " ";
  }
}
