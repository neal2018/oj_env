#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
const ll MOD = 1e9 + 7;
ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a, maxi = 1e7 + 10;
  cin >> T;
  auto solve = [&] {

  };
  while (T--) {
    cin >> a;
    solve();
  }
}