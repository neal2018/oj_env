#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

ll get_sqrt(ll x) {
  ll l = 1, r = x;
  while (l < r) {
    ll mid = l + (r - l + 1) / 2;
    if ((__int128)mid * mid <= x) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll l, r;
    cin >> l >> r;
    auto lx = get_sqrt(l), rx = get_sqrt(r);
    if (lx == rx) {
      ll res = r / rx - (l - 1) / lx;
      cout << res << "\n";
      continue;
    }
    ll res = (rx - 1 - (lx + 1) + 1) * 3;
    res += ((lx + 1) * (lx + 1) - 1) / lx - (l - 1) / lx;
    res += r / rx - (rx * rx - 1) / rx;
    cout << res << "\n";
  }
}
