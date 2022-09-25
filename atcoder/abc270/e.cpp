#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  auto go = [&] {
    auto check = [&](ll mid) {
      ll cur = 0;
      for (auto& x : a) {
        cur += min(x, mid);
      }
      return cur <= k;
    };
    ll l = 0, r = k;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return l;
  }();
  ll remain = k;
  for (auto& x : a) remain -= min(x, go), x -= min(x, go);
  for (int i = 0; i < n; i++) {
    if (remain && a[i] > 0) {
      remain--, a[i]--;
    }
    if (remain == 0) break;
  }
  for (auto& x : a) cout << x << " ";
  cout << "\n";
}
