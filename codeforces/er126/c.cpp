#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end(), greater<>());
    ll res = 1e18;
    for (auto t : {a[0], a[0] + 1}) {
      ll odd = 0, even = 0;
      for (auto& x : a) {
        ll need = t - x;
        if (need & 1) {
          odd++, need--;
        }
        even += need / 2;
      }
      ll mini = min(odd, even);
      odd -= mini, even -= mini;
      mini *= 2;
      if (odd == 0) {
        even *= 2;
        ll extra = even / 3;
        mini += extra * 2, even %= 3;
        if (even == 1) mini++;
        if (even == 2) mini += 2;
      } else {
        mini += odd * 2 - 1;
      }
      res = min(res, mini);
    }
    cout << res << "\n";
  };
}
