#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    vector<int> white, black;
    function<void(int, int, int)> dfs = [&](int node, int fa, int color) {
      (color ? black : white).push_back(node);
      for (auto& ne : g[node])
        if (ne != fa) dfs(ne, node, !color);
    };
    dfs(0, -1, 0);
    if (white.size() > black.size()) swap(white, black);
    int w = (int)white.size();
    vector<int> p(n), seen(n + 1);
    for (int i = 1, cur = 0; i <= w; i *= 2) {
      if (w & i) {
        for (int j = i; j < i * 2; j++) {
          p[white[cur++]] = j, seen[j] = 1;
        }
      }
    }
    for (int i = 1, cur = 0; i <= n; i++)
      if (!seen[i]) p[black[cur++]] = i;
    for (int i = 0; i < n; i++) cout << p[i] << ' ';
    cout << '\n';
  }
}