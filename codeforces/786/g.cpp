#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> e(m);
  vector<ll> in(n), out(n), deg(n);
  for (auto& [u, v] : e) {
    cin >> u >> v, u--, v--;
    in[v]++, out[u]++;
  }
  vector<vector<ll>> g(n);
  for (auto& [u, v] : e) {
    if (out[u] != 1 && in[v] != 1) {
      g[u].push_back(v);
      deg[v]++;
    }
  }
  vector<ll> dp(n);
  ll res = 0;
  vector<ll> q, nq;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      dp[i] = 1;
      q.push_back(i);
    }
  }
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      res = max(res, dp[node]);
      for (auto& ne : g[node]) {
        deg[ne]--, dp[ne] = max(dp[ne], dp[node] + 1);
        if (deg[ne] == 0) {
          nq.push_back(ne);
        }
      }
    }
  }
  cout << res << "\n";
}
