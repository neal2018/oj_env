#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a))
    if (b & 1) (res *= a);
  return res;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll k, L, R;
  cin >> L >> R >> k;
  __int128 res = 0;
  if (k == 1) {
    res = (__int128)((__int128)L + R) * (R - L + 1) / 2;
  } else if (k == 2) {
    auto f = [](ll x) {
      __int128 ans = 0;
      // max n s.t. (n+1)^2-1 < x
      __int128 l = 0, r = 1e10;
      while (l < r) {
        __int128 mid = (l + r + 1) / 2;
        if ((mid + 1) * (mid + 1) - 1 < x) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      ans = l * (l + 1) * (2 * l + 1) / 3 + l * (l + 1) / 2;
      ans += (l + 1) * (x - (l + 1) * (l + 1) + 1);
      return ans;
    };
    res = f(R) - f(L - 1);
  } else {
    ll s = pow(L, (long double)1.0 / k);
    __int128 t = power(s + 1, k);
    for (ll l = L, r; l <= R; l = r + 1) {
      // find max r, s.t. r^(1/k) = l^(1/k)
      r = min(power(s + 1, k) - 1, R);
      res += s * (r - l + 1);
      s++;
    }
  }
  vector<int> out;
  if (!res) out = {0};
  while (res) out.push_back(res % 10), res /= 10;
  reverse(out.begin(), out.end());
  for (auto x : out) cout << x;
  cout << '\n';
}