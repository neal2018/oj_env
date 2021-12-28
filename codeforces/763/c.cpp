#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> aa(n);
    for (auto& x : aa) cin >> x;
    ll l = 1, r = 1e9;
    auto check = [&](ll mid) {
      auto a = aa;
      for (int i = n - 1; i >= 2; i--) {
        ll can_give = max(0ll, a[i] - mid);
        can_give = can_give / 3 * 3;
        ll maxi = aa[i] / 3 * 3;
        can_give = min(maxi, can_give);
        ll give = can_give / 3;
        a[i] -= 3 * give, a[i - 1] += give, a[i - 2] += 2 * give;
        if (a[i] < 0) return false;
      }
      return (*min_element(a.begin(), a.end())) >= mid;
    };
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << "\n";
  }
}