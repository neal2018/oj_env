#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m, k;
  cin >> m >> n >> k;
  vector<map<ll, ld>> dp(n);
  dp[1][k + 1] = 1;
  vector<tuple<ll, ll, ll, ll, ld>> edges(m);
  for (auto& [s, t, a, b, p] : edges) {
    cin >> a >> b >> s >> t >> p;
  }
  sort(edges.begin(), edges.end(), greater<>());
  for (auto& [s, t, a, b, p] : edges) {
    ld addon = 0, nex = 0;
    auto wait = dp[a].upper_bound(s);
    auto reach = dp[b].upper_bound(t);
    if (wait != dp[a].end()) addon = wait->second;
    if (reach != dp[b].end()) nex = reach->second;
    dp[a][s] = max({dp[a][s], addon, p * nex + (1 - p) * addon});
  }
  cout << dp[0].begin()->second << "\n";
}
