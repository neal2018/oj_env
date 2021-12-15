#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll d1 = 0, d2 = 0, f1 = 1, f2 = 1;
    for (int i = 0; i < n; i += 2) d1 = gcd(d1, a[i]);
    for (int i = 1; i < n && f1; i += 2)
      if (a[i] % d1 == 0) f1 = 0;
    for (int i = 1; i < n; i += 2) d2 = gcd(d2, a[i]);
    for (int i = 0; i < n && f2; i += 2)
      if (a[i] % d2 == 0) f2 = 0;
    if (f1) {
      cout << d1 << '\n';
    } else if (f2) {
      cout << d2 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
}