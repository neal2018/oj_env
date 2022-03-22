#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MAX = 9 * 12 + 1;

ll memo[MAX][MAX][MAX][12][2];
ll solve(ll x) {
  ll ans = 0;
  vector<ll> a;
  while (x) a.push_back(x % 10), x /= 10;
  reverse(a.begin(), a.end());
  int n = int(a.size());
  for (ll K = 1; K < MAX; K++) {
    function<ll(ll, ll, ll, ll, ll)> dfs = [&](ll cur, ll pre, ll prod, ll sum, ll limit) {
      auto &vv = memo[K][prod][sum][n - cur][pre == -1];
      if (limit == 0 && vv != 0) return vv - 1;
      ll res = 0;
      if (cur == n) {
        if (sum == K) res = (prod == 0);
      } else {
        ll maxi = (limit ? a[cur] + 1 : 10);
        for (int i = 0; i < maxi; i++) {
          ll nex = (i == 0 && pre == -1) ? -1 : i;
          ll pp = nex == -1 ? 1 : (prod * i) % K;
          ll ss = nex == -1 ? 0 : (sum + i);
          res += dfs(cur + 1, nex, pp, ss, limit && (i == a[cur]));
        }
      }
      if (limit != 1) {
        vv = res + 1;
      }
      return res;
    };
    ans += dfs(0, -1, 1, 0, 1);
  }
  return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    ll l, r;
    cin >> l >> r, l--;
    cout << solve(r) - solve(l) << "\n";
  }
}
