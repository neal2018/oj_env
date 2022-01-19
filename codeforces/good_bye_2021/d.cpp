#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    cin >> k;
    for (auto& x : a) x -= k;
    ll s = a[0], cnt = 1, mini = a[0], rolling = 1;
    for (int i = 1; i < n; i++) {
      if (!rolling || mini + a[i] >= 0) {
        mini = rolling ? min(mini + a[i], a[i]) : a[i];
        s += a[i], cnt++, rolling = 1;
      } else {
        s = 0, mini = 0, rolling = 0;
      }
    }
    cout << cnt << "\n";
  }
}