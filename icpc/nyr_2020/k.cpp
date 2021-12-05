#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll p, q;
  cin >> p >> q;
  function<ll(ll, ll)> help = [&](ll a, ll b) {
    if (a == 1 && b == 1) return 1ll;
    // if (a == 1 && b == 2) return 2ll;
    if (a > b) return (help(a - b, a) + 1) % MOD;
    ll c = b - a, res;
    if (c >= a) {
      res = (help(a, c) * 2) % MOD;
    } else {
      res = (help(a - c, a) * 2 + 2) % MOD;
    }
    return res;
  };
  cout << help(p, q) << '\n';
}