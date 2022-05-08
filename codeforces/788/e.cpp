#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll p;
    cin >> p;
    ll n = 1 << p;
    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back({v, i}), g[v].push_back({u, i});
    }
    vector<ll> res(n), ree(n - 1);
    res[0] = n;
    ll cur = 1;
    function<void(ll, ll, ll)> dfs = [&](ll node, ll fa, ll f) {
      for (auto& [ne, e] : g[node]) {
        if (ne == fa) continue;
        ree[e] = cur ^ n, res[ne] = cur;
        if (!f) swap(ree[e], res[ne]);
        cur++;
        dfs(ne, node, !f);
      }
    };
    dfs(0, -1, 1);
    cout << 1 << '\n';
    for (auto& x : res) cout << x << " ";
    cout << '\n';
    for (auto& x : ree) cout << x << " ";
    cout << '\n';
  }
}
