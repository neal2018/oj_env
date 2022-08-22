#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, p, q, rr;
  cin >> n >> p >> q >> rr;
  vector<ll> a(n), pre(n + 1);
  for (auto& x : a) cin >> x;
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
  for (int i = 0; i < n; i++) {
    auto get = [&](ll start, ll need) {
      ll l = start, r = n;
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (pre[mid] - pre[start] <= need) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      if (pre[l] - pre[start] == need) {
        return l;
      } else {
        return -1ll;
      }
    };
    // y
    auto y = get(i, p);
    if (y == -1) continue;
    auto z = get(y, q);
    if (z == -1) continue;
    auto w = get(z, rr);
    if (w == -1) continue;
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
}
