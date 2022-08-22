#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<ll, ll>>> g(n);
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w, u--, v--;
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }
  auto dij = [&](vector<ll>& dist) {
    set<pair<ll, ll>> st;
    for (int i = 0; i < n; i++) st.insert({dist[i], i});
    while (st.size()) {
      auto [c, node] = *st.begin();
      st.erase(st.begin());
      for (auto& [ne, w] : g[node]) {
        if (w + c < dist[ne]) {
          dist[ne] = w + c;
          st.insert({dist[ne], ne});
        }
      }
    }
  };
  vector<ll> dp(n, inf);
  dp[0] = 0;
  dij(dp);
  for (int _ = 0; _ < k; _++) {
    auto ndp = dp;
    function<void(int, int, int, int)> solve = [&](int l, int r, int opt_l, int opt_r) {
      if (l >= r) return;
      int mid = (l + r) / 2, best = opt_l;
      for (int i = opt_l; i < opt_r; i++) {
        ll cost = dp[i] + ll(i - mid) * (i - mid);
        if (cost <= ndp[mid]) best = i, ndp[mid] = cost;
      }
      solve(l, mid, opt_l, best + 1), solve(mid + 1, r, best, opt_r);
    };
    solve(0, n, 0, n);
    swap(ndp, dp);
    dij(dp);
  }
  for (auto& x : dp) cout << x << ' ';
  cout << "\n";
}
