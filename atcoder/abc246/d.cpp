#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  auto cal = [](ll a, ll b) { return a * a * a + a * a * b + a * b * b + b * b * b; };
  ll res = 2e18;
  for (ll i = 0; i * i * i <= n; i++) {
    ll l = 0, r = 1e6 + 10;
    while (l < r) {
      ll mid = (l + r) / 2;
      ll t = cal(i, mid);
      if (t >= n) {
        res = min(res, t);
        r = mid;
      } else {
        l = mid + 1;
      }
    }
  }
  cout << res << "\n";
}
