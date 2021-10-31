#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
ll power(ll a, ll b, int res = 1) {
  for (; b; b >>= 1, a = a * a % MOD)
    if (b & 1) res = res * a % MOD;
  return res;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n), pre(n + 1);
    ll sum = 0, one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) one++;
      if (a[i] == 0) zero++;
    }
    cout << (one << zero) << '\n';
  }
}