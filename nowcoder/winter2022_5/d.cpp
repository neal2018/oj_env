#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19};

ll solve(ll x) {
  map<array<ll, 4>, ll> memo;
  vector<ll> a;
  while (x) a.push_back(x % 10), x /= 10;
  reverse(a.begin(), a.end());
  int n = int(a.size());
  function<ll(ll, ll, ll, ll)> dfs = [&](ll cur, ll pre, ll has_one, ll limit) {
    if (memo.count({cur, pre, has_one, limit})) return memo[{cur, pre, has_one, limit}];
    ll res = 0;
    if (cur == n) {
      res = has_one;
    } else {
      ll maxi = (limit ? a[cur] + 1 : 10);
      for (int i = 0; i < maxi; i++) {
        if (pre == -1 || primes.count(i + pre)) {
          ll nex = (i == 0 && pre == -1) ? -1 : i;
          res += dfs(cur + 1, nex, has_one || (i == 1), limit && (i == a[cur]));
        }
      }
    }
    return memo[{cur, pre, has_one, limit}] = res;
  };
  return dfs(0, -1, 0, 1);
}

int main() {
  cout << fixed << setprecision(10);
  ll l, r;
  cin >> l >> r, l--;
  cout << solve(r) - solve(l) << "\n";
}
