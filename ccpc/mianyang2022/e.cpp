#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;
constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w, u--, v--;
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }

  vector<int> qs(q);
  for (auto& x : qs) cin >> x, x--;
  vector<ll> dp(n);

  const int threshold = int(sqrt(m) + 1);
  vector<vector<array<ll, 3>>> dp_c(n);
  vector<int> heavies, is_heavy(n);
  for (int i = 0; i < n; i++) {
    if (g[i].size() > threshold) heavies.push_back(i), is_heavy[i] = 1;
  }

  for (int i = q - 1; i >= 0; i--) {
    if ((q - 1 - i) % threshold == 0) {
      for (auto& node : heavies) {
        dp_c[node].clear();
        dp_c[node].reserve(g[node].size());
        for (auto [ne, w] : g[node]) {
          dp_c[node].push_back({dp[ne] + w, ne, w});
        }
        nth_element(dp_c[node].begin(), dp_c[node].begin() + threshold, dp_c[node].end());
      }
    }
    int node = qs[i];
    dp[node] = inf;
    if (is_heavy[node]) {
      for (int j = 0; j <= threshold; j++) {
        auto [val, ne, w] = dp_c[node][j];
        dp[node] = min(dp[node], dp[ne] + w);
      }
    } else {
      for (auto& [ne, w] : g[node]) {
        dp[node] = min(dp[node], dp[ne] + w);
      }
    }
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    (res += a[i] * dp[i]) %= MOD;
  }
  cout << res << "\n";
}
