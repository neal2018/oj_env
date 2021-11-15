#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  auto ask = [&](ll l, ll r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    ll res = 0;
    cin >> res;
    return res;
  };
  while (T--) {
    cin >> n;
    cout << '\n';
    ll save = 0;
    ll total = ask(0, n - 1);
    ll l = 0, r = n - 1;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      ll pre = ask(0, mid);
      if (pre < total) {
        l = mid;
        save = max(save, pre);
      } else {
        r = mid - 1;
      }
    }
    // r=k-1;
    ll k = l + 1;
    // d2 = k-j+1 =
    ll d2 = total - save + 1;
    ll j = k + 1 - d2;
    // d1 = j-i
    ll remain = total - d2 * (d2 - 1) / 2;
    {
      ll l = 0, r = n - 1;
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (mid * (mid - 1) / 2 <= remain) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      // d1 = l
      ll i = j - l;
      cout << "! " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    }
  }
}