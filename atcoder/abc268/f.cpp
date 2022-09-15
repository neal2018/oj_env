#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<pair<int, int>> edges(n);
  for (auto& [u, v] : edges) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }

  int cnt = 0, now = 0;
  vector<int> dfn(n, -1), low(n), belong(n, -1), stk;
  function<void(int, int)> tarjan = [&](int node, ll fa) {
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
    if (dfn[i] == -1) tarjan(i, -1);
  }

  auto id = [&] {
    vector<int> freq(cnt);
    for (auto& x : belong) freq[x]++;
    for (int i = 0; i < cnt; i++) {
      if (freq[i] > 1) return i;
    }
    return -1;
  }();

  vector<int> color(n, -1);
  for (int i = 0; i < n; i++) {
    if (belong[i] == id) color[i] = -2;
  }

  function<void(int, int)> dfs = [&](int node, int col) {
    color[node] = col;
    for (auto& ne : g[node]) {
      if (color[ne] == -1) dfs(ne, col);
    }
  };

  for (int i = 0; i < n; i++) {
    if (belong[i] == id) dfs(i, i);
  }

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y, x--, y--;
    if (color[y] == -2) swap(x, y);
    if (color[x] != -2) {
      cout << (color[x] == color[y] ? "Yes\n" : "No\n");
    } else {
      cout << (x == color[y] ? "Yes\n" : "No\n");
    }
  }
}
