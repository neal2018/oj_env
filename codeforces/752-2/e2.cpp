#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9, MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  vector<vector<int>> nodes(2), dp(2, vector<int>(N));
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    ll res = 0;
    for (int i = n - 1; i >= 0; i--) {
      int k = i & 1;
      nodes[k].push_back(a[i]);
      dp[k][a[i]] = 1;
      int last = a[i];
      for (auto v : nodes[k ^ 1]) {
        int t = (a[i] + v - 1) / v;
        (res += 1LL * (t - 1) * dp[k ^ 1][v] * (i + 1)) %= MOD;
        dp[k][a[i] / t] += dp[k ^ 1][v];
        if (last != a[i] / t) nodes[k].push_back(a[i] / t), last = a[i] / t;
        dp[k ^ 1][v] = 0;
      }
      nodes[k ^ 1].clear();
    }
    cout << res << '\n';
    for (auto x : nodes[0]) dp[0][x] = 0;
    nodes[0].clear();
  }
  return 0;
}