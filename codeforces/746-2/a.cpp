#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, h;
  cin >> T;
  while (T--) {
    cin >> n >> h;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll cnt = 2 * (h / (a[1] + a[0]));
    h %= (a[1] + a[0]);
    if (h == 0) {
      cout << cnt << '\n';
    } else if (h <= a[0]) {
      cout << cnt + 1 << '\n';
    } else {
      cout << cnt + 2 << '\n';
    }
  }
}