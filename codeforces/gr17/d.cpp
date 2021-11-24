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
  ll n, cnt = 0;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x, x &= -x;
  ranges::sort(a);
  for (int i = 0; i < n; i++) {
    if (a[i] == 1 || (i != 0 && a[i] == a[i - 1])) continue;
    (cnt += power(2, n - i - 1)) %= MOD;
  }
  cout << (power(2, n) - cnt - 1 + MOD) % MOD << '\n';
}