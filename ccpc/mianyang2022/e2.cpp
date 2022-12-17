#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<priority_queue<tuple<ll, ll, ll>>> g(n);
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w, u--, v--;
    g[u].push({-w, w, v}), g[v].push({-w, w, u});
  }
  vector<int> qs(q);
  for (auto& x : qs) cin >> x, x--;
  reverse(qs.begin(), qs.end());
  vector<ll> dp(n);
  for (auto node : qs) {
    auto [val, w, ne] = g[node].top();
    while (dp[ne] != -val - w) {
      g[node].pop();
      g[node].push({-dp[ne] - w, w, ne});
      tie(val, w, ne) = g[node].top();
    }
    dp[node] = -val;
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    (res += a[i] * dp[i]) %= MOD;
  }
  cout << res << "\n";
}
