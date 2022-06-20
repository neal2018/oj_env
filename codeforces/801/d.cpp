#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
      deg[u]++, deg[v]++;
    }
    int root = int(ranges::max_element(deg) - deg.begin());
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    if (n == 2 || n == 3) {
      cout << "1\n";
      continue;
    }
    function<ll(int, int)> dfs = [&](int node, int fa) {
      ll good = 0, res = 0, cnt = 0;
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        ll sub = dfs(ne, node);
        cnt++, res += sub;
        if (sub != 0) good++;
      }
      if (cnt == 0) return 0ll;
      ll extra = max(0ll, cnt - 1 - good);
      return res + extra;
    };
    ll res = dfs(root, -1);
    cout << res << "\n";
  }
}
