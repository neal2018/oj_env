#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  auto f = [&]() {
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll diff1 = -1, diff2 = -1;
    for (ll l = 0, r = n - 1; l < r; l++, r--) {
      if (a[l] != a[r]) {
        diff1 = a[l], diff2 = a[r];
        break;
      }
    }
    if (diff1 == -1) {
      cout << "YES\n";
    } else {
      vector<ll> diff = {diff1, diff2};
      for (auto &d : diff) {
        int can = 1;
        for (ll l = 0, r = n - 1; l < r && can;) {
          if (a[l] != a[r]) {
            if (a[l] == d) {
              l++;
            } else if (a[r] == d) {
              r--;
            } else {
              can = 0;
              break;
            }
          } else {
            l++, r--;
          }
        }
        if (can) {
          cout << "YES\n";
          return;
        }
      }
      cout << "NO\n";
    }
  };
  while (T--) {
    f();
  }
}