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
    ll n, k, root, target;
    cin >> n >> k >> root >> target, root--, target--;
    vector<ll> a(k), mark(n);
    for (auto& x : a) cin >> x, x--, mark[x] = 1;
    // a.push_back(target);
    mark[target] = 1;
    vector<vector<ll>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    ll res = 0, target_dep = 0;

    function<ll(ll, ll, ll)> dfs = [&](ll node, ll fa, ll dep) {
      ll cnt = mark[node];
      if (node == target) target_dep = dep;
      if (mark[node]) res += dep;
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        cnt += (dfs(ne, node, dep + 1) > 0);
      }
      if (cnt) {
        res -= (cnt - 1) * dep;
      }
      return cnt;
    };
    dfs(root, -1, 0);
    res *= 2;
    res -= target_dep;
    cout << res << "\n";
  }
}
