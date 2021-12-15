#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr ll MOD = 1e9 + 7;
ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    ll a = 0;
    for (int i = 0, l, r, x; i < m; i++) cin >> l >> r >> x, a |= x;
    cout << (a * power(2, n - 1)) % MOD << '\n';
  }
}