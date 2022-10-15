#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 1, p; i < n; i++) {
      cin >> p, p--;
      g[p].push_back(i);
    }
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> w(n);
    function<void(int, int)> get_leave = [&](int node, int fa) {
      w[node] = a[node];
      if (fa != -1) {
        w[node] += w[fa];
      }
      for (auto& ne : g[node]) {
        get_leave(ne, node);
      }
    };
    get_leave(0, -1);
    function<void(int)> get_w = [&](int node) {
      for (auto& ne : g[node]) {
        get_w(ne);
        w[node] = max(w[node], w[ne]);
      }
    };
    get_w(0);
    map<pair<int, int>, ll> mp;
    function<ll(int, int)> dfs = [&](int node, int cur) {
      if (mp.count({node, cur})) return mp[{node, cur}];
      int sz = int(g[node].size());
      if (sz == 0) {
        return cur * w[node];
      }
      int need = cur / sz;
      int extra = cur - need * sz;
      vector<array<ll, 2>> poss;
      poss.reserve(sz);
      ll res = 0;
      for (auto& ne : g[node]) {
        if (extra == 0) {
          res += dfs(ne, need);
        } else {
          auto x = dfs(ne, need);
          auto y = dfs(ne, need + 1);
          poss.push_back({y - x, x});
        }
      }
      if (extra == 0) return mp[{node, cur}] = res;
      sort(poss.begin(), poss.end(), greater());
      for (auto [add, now] : poss) {
        if (extra) {
          res += add, extra--;
        }
        res += now;
      }
      return mp[{node, cur}] = res;
    };
    auto res = dfs(0, k);
    cout << res << "\n";
  }
}
