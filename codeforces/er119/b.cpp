#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    ll w, h, res = 0;
    cin >> w >> h;
    for (int i = 0; i < 4; i++) {
      ll n, mini = 1e7, maxi = -1e7;
      cin >> n;
      for (ll j = 0, x; j < n; j++) {
        cin >> x;
        mini = min(mini, x);
        maxi = max(maxi, x);
      }
      res = max(res, (maxi - mini) * (i < 2 ? h : w));
    }
    cout << res << '\n';
  };
  while (T--) f();
}