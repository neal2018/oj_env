#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, u, v;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    int res = 0;
    function<int(int, int)> dfs = [&](int node, int fa) {
      if (node && g[node].size() == 1) return 0;
      vector<int> a;
      for (auto& ne : g[node])
        if (ne != fa) a.push_back(dfs(ne, node));
      ranges::sort(a);
      if (a.size() > 1)
        res = node ? max(res, a.back() + 2) : max({res, a.back() + 1, a[a.size() - 2] + 2});
      res = max(res, a[0] + 1);
      return a[0] + 1;
    };
    dfs(0, -1);
    cout << res << '\n';
  }
}