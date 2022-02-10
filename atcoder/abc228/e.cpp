#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;

ll power(ll a, ll b, ll MOD = MOD, ll res = 1) {
  a %= MOD;
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k, m;
  cin >> n >> k >> m;
  cout << power(m, power(k, n, MOD - 1) + MOD - 1) << '\n';
}
