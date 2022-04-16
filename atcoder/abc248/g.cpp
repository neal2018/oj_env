#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 1; i < n; i++) cin >> a[i];
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  auto check = [&](ll mid) {
    // number need to win
    function<int(int, int)> dfs = [&](int node, int fa) {
      int res = 0;
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        auto nex = dfs(ne, node);
        res += nex + (a[ne] >= mid);
      }
      return max(res - 1, 0);
    };
    return dfs(0, -1) > 0;
  };
  ll l = 0, r = 1e9;
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << "\n";
}
