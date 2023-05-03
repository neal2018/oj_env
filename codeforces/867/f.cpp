#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k, c;
    cin >> n >> k >> c;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    vector<ll> dep(n), max_dep(n);
    function<void(int, int)> get_dep = [&](int node, int fa) {
      if (fa != -1) {
        dep[node] = dep[fa] + 1;
      }
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        get_dep(ne, node);
        max_dep[node] = max(max_dep[node], max_dep[ne] + 1);
      }
    };
    get_dep(0, -1);

    ll res = 0;
    function<void(int, int, ll)> dfs = [&](int node, int fa, ll dist) {
      ll largest = max(dist, max_dep[node]);
      res = max(res, largest * k - dep[node] * c);
      ll maxi1 = dist, maxi2 = 0;
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        ll cur = max_dep[ne] + 1;
        if (cur > maxi1) {
          maxi2 = maxi1, maxi1 = cur;
        } else if (cur > maxi2) {
          maxi2 = cur;
        }
      }
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        ll cur = max_dep[ne] + 1;
        dfs(ne, node, ((cur == maxi1) ? maxi2 : maxi1) + 1);
      }
    };

    dfs(0, -1, 0);
    cout << res << "\n";
  }
}
