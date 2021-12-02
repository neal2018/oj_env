#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr ll MOD = 998244353;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    map<ll, ll> dp1, dp2;  // dp[mex]: max is mex-1, mex+1
    ll res = 0;
    for (auto& x : a) {
      (dp2[x - 1] += dp2[x - 1] + dp1[x - 1] + (x == 1)) %= MOD;
      (dp2[x + 1] += dp2[x + 1]) %= MOD;
      (dp1[x + 1] += dp1[x + 1] + dp1[x] + (x == 0)) %= MOD;
    }
    for (auto& [k, v] : dp1) (res += v) %= MOD;
    for (auto& [k, v] : dp2) (res += v) %= MOD;
    cout << res << '\n';
  }
}