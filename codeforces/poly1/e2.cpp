#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, d;
  cin >> n >> d;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  array<vector<int>, 2> a{vector<int>(n), vector<int>(n)};
  for (auto& r : a) {
    int m;
    cin >> m;
    for (int i = 0, x; i < m; i++) cin >> x, x--, r[x] = 1;
  }
  vector<int> stk;
  function<void(int, int)> dfs = [&](int node, int fa) {
    stk.push_back(node);
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
      for (auto& r : a) r[node] |= r[ne];
    }
    stk.pop_back();
    if (stk.size() >= d) {
      int anc = stk[int(stk.size()) - d];
      for (auto i : {0, 1}) a[i][anc] |= a[!i][node];
    }
  };
  dfs(0, -1);
  int res = 0;
  for (auto& r : a) res += accumulate(r.begin(), r.end(), 0);
  cout << (res - 2) * 2 << "\n";
}
