#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i] + b[i];
    map<pair<ll, ll>, ll> memo;
    function<ll(ll, ll)> dfs = [&](ll sum, ll cur) {
      if (memo.count({sum, cur})) return memo[{sum, cur}];
      if (cur == n) return 0ll;
      ll b_sum = pre[cur] - sum;
      ll not_swap = sum * a[cur] + b_sum * b[cur] + dfs(sum + a[cur], cur + 1);
      ll do_swap = sum * b[cur] + b_sum * a[cur] + dfs(sum + b[cur], cur + 1);
      ll res = min(not_swap, do_swap);
      return memo[{sum, cur}] = res;
    };
    ll res = 2 * dfs(0, 0);
    for (int i = 0; i < n; i++) {
      res += a[i] * a[i] * (n - 1);
      res += b[i] * b[i] * (n - 1);
    }
    cout << res << "\n";
  }
}
