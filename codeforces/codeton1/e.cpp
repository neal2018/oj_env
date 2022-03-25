#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    vector<ll> res(n), k(n), sum(n);
    function<void(ll, ll)> dfs = [&](ll node, ll fa) {
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        dfs(ne, node);
        k[node]++;
      }
    };
    dfs(0, -1);
    ll T = 0, total_k = 0;
    for (auto& x : k) {
      if (x != 0) T += (x + 1);
      total_k += x;
    }
    function<void(ll, ll, ll)> dfs2 = [&](ll node, ll fa, ll pass) {
      if (k[node] != 0) {
        sum[node] = total_k + 1;
        res[node] = sum[node] * (k[node] + 1) - k[node] * T;
      } else {
        res[node] = pass;
      }
      if (k[node]) {
        ll child = (sum[node] - res[node]) / k[node];
        for (auto& ne : g[node]) {
          if (ne == fa) continue;
          dfs2(ne, node, child);
        }
      }
    };
    dfs2(0, -1, T);
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
