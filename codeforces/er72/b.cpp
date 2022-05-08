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
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    if (pre[n] <= s) {
      cout << "0\n";
      continue;
    }
    ll maxi = -1, id = 0;
    for (int i = 0; i < n; i++) {
      auto check = [&](ll mid) {
        ll cur = pre[mid + 1];
        if (mid >= i) cur -= a[i];
        return cur <= s;
      };
      ll l = -1, r = n - 1;
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid)) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      if (l >= i) l--;
      if (l > maxi) maxi = l, id = i;
    }
    cout << id + 1 << "\n";
  }
}
