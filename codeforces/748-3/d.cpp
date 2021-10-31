#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll g = -1;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i - 1]) {
        if (g == -1) {
          g = a[i] - a[i - 1];
        } else {
          g = __gcd(g, a[i] - a[i - 1]);
        }
      }
    }
    cout << g << '\n';
  }
}