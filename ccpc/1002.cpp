#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a, b, c, x0, x1, y0, y1, y2;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> x0 >> x1 >> y0 >> y1 >> y2;
    function<ll(ll)> f = [&](ll x) { return x * x * a + x * b + c; };
    if (f(x0) > y0 && f(x1) < y0) {
      cout << "Yes\n";
    } else if (f(x0) > y0 && f(x1) > y0 && f(x1) <= y2 && f(2 * x1 - x0) < y0) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}