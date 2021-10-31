#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k, MOD = 1e9 + 7;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    ll ans = 0, cnt = 0;
    auto power = [&](ll a, ll b) {
      ll res = 1;
      for (; b; b /= 2, (a *= a) %= MOD) {
        if (b & 1) (res *= a) %= MOD;
      }
      return res;
    };
    for (; k; k /= 2, cnt++) {
      if (k & 1) (ans += power(n, cnt)) %= MOD;
    }
    cout << ans << '\n';
  }
}