#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k, u, v;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    vector<ll> a(n), xx(n);
    ll t = 0;
    for (auto& x : a) {
      cin >> x;
      t ^= x;
    }
    vector<vector<int>> g(n);
    for (ll i = 0; i < n - 1; i++) {
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if (t == 0) {
      cout << "YES\n";
      continue;
    }
    function<ll(ll, ll)> dfs1 = [&](ll node, ll fa) {
      ll tt = a[node];
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        tt ^= dfs1(ne, node);
      }
      return xx[node] = tt;
    };
    dfs1(0, -1);
    function<tuple<ll, ll>(ll, ll)> dfs = [&](ll node, ll fa) {
      ll cut = 0, remain = xx[node];
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        auto [x, get] = dfs(ne, node);
        cut += x;
        remain = remain ^ xx[ne] ^ get;
        if (get == t) {
          cut++;
          remain ^= t;
        }
      }
      return tuple{cut, remain};
    };
    auto [x, y] = dfs(0, -1);
    if (x > 1 && k > 2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}