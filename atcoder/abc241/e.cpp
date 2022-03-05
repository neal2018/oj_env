#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll res = 0;
  // res <- res + a[res%N]
  map<ll, pair<ll, ll>> mp{{0, {0, 0}}};
  for (ll i = 1; i <= k; i++) {
    if (res < 0) break;
    res += a[res % n];
    if (mp.count(res % n)) {
      auto [pre, pre_val] = mp[res % n];
      ll diff = i - pre;
      ll can = (k - i) / diff;
      res += can * (res - pre_val);
      i += can * diff;
    } else {
      mp[res % n] = {i, res};
    }
  }
  cout << res << "\n";
}
