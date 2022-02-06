#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b;
    cin >> a >> b;
    ll res = b - a;
    if ((a | b) == b) res = 1;
    for (ll i = a; i <= b; i++) {
      ll addon = i - a;
      ll c = i | b;
      addon += c - b + 1;
      res = min(res, addon);
    }
    for (ll i = b; i <= 2 * b; i++) {
      ll addon = i - b;
      ll c = i | a;
      addon += c - i + 1;
      res = min(res, addon);
    }
    cout << res << "\n";
  }
}