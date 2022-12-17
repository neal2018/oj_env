#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a))
    if (b & 1) (res *= a);
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    function<ll(ll, ll, ll, ll)> dfs = [&](ll cur, ll i, ll green, ll blue) {
      if (i == n) return n;
      if (cur > a[i]) {
        return dfs(cur + a[i] / 2, i + 1, green, blue);
      } else {
        ll res = i;
        if (green) {
          res = max(res, dfs(cur * 2, i, green - 1, blue));
        }
        if (blue) {
          res = max(res, dfs(cur * 3, i, green, blue - 1));
        }
        return res;
      }
    };
    auto res = dfs(h, 0, 2, 1);
    cout << res << "\n";
  }
}
