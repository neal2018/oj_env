#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
unordered_map<char, int> color_index = {{'w', 0}, {'y', 1}, {'g', 2}, {'b', 3}, {'r', 4}, {'o', 5}};
ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll k, n, x;
  string s;
  cin >> k >> n;
  unordered_map<ll, ll> mp;
  unordered_set<ll> marked;
  for (int i = 0; i < n; i++) {
    cin >> x >> s;
    mp[x] = color_index[s[0]];
    for (; x; x /= 2) marked.insert(x);
  }
  map<pair<ll, ll>, ll> dp;
  ll total = (1ll << k) - 1, no_child = (1ll << (k - 1)) - 1, res = 0;
  function<ll(ll, ll)> dfs = [&](ll node, ll color) {
    if (dp.count({node, color})) return dp[{node, color}];
    if (node > total || !marked.count(node) || (mp.count(node) && mp[node] != color)) return 0LL;
    ll left = (!marked.count(2 * node) || node > no_child) ? 1 : 0;
    ll right = (!marked.count(2 * node + 1) || node > no_child) ? 1 : 0;
    for (int col = 0; col < 6; col++) {
      if (col / 2 == color / 2) continue;
      (left += dfs(2 * node, col)) %= MOD;
      (right += dfs(2 * node + 1, col)) %= MOD;
    }
    return dp[{node, color}] = (left * right) % MOD;
  };
  for (int col = 0; col < 6; col++) (res += dfs(1, col)) %= MOD;
  cout << (res * power(4, total - marked.size())) % MOD << '\n';
}