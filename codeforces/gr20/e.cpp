#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto ask = [&](ll x) {
    if (x <= 0) return 0ll;
    cout << "? " << x << endl;
    ll res = 0;
    cin >> res;
    return res;
  };
  ll n;
  cin >> n;
  ll l = 0, r = 2000 * 2000;
  while (l < r) {
    ll mid = (l + r) / 2;
    auto h = ask(mid);
    if (h > 1 || h == 0) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  ll res = l;
  for (int k = 1; k < n; k++) {
    ll w = l / (k + 1);
    auto h = ask(w);
    if (h > 0) {
      res = min(res, w * h);
    }
  }
  cout << "! " << res << endl;
}
