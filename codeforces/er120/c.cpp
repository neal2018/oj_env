#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ranges::sort(a);
    vector<ll> pre(n + 1);
    for (ll i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    auto check = [&](ll mid) {
      for (ll b = 0; b <= min(mid, n - 1); b++) {
        ll aa = mid - b;
        ll mini = a[0] - aa;
        ll temp = pre[n] - aa;
        ll total = pre[n] - pre[n - b];
        temp -= total - b * (mini);
        if (temp <= k) return true;
      }
      return false;
    };
    ll l = 0, r = 1e18;
    while (l < r) {
      ll mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r << '\n';
  }
}