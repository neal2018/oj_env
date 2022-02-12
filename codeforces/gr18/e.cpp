#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> a;
  function<int(int, int)> dfs = [&](int node, int fa) {
    vector<int> tmp;
    for (auto& ne : g[node]) {
      if (ne != fa) tmp.push_back(dfs(ne, node));
    }
    ranges::sort(tmp, greater());
    for (int i = 1; i < tmp.size(); i++) a.push_back(tmp[i]);
    return tmp.size() ? tmp[0] + 1 : 1;
  };
  a.push_back(dfs(0, -1));
  ranges::sort(a, greater());
  ll res = -1e18;
  for (int i = 0, x = n; i <= k; i++) {
    if (0 < i && i <= a.size()) x -= a[i - 1];
    ll blue = min(n / 2, x);
    res = max(res, (n - i - blue) * (i - blue));
  }
  cout << res << "\n";
}
