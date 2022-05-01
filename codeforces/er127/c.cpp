#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    ll res = 0, cur_day = 0;
    for (ll i = n - 1; i >= 0; i--) {
      auto check = [&](ll mid) {
        // sum a[0]+mid + ... + a[i] + mid <= m
        return pre[i + 1] + mid * (i + 1) <= m;
      };
      ll l = cur_day, r = 1e12;
      while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      res += (r - cur_day) * (i + 1), cur_day = r;
    }
    cout << res << "\n";
  }
}
