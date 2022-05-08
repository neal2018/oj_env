#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    auto c = a;
    sort(c.begin(), c.end());
    ll f = 1;
    for (ll i = n - 1; i >= 1 && f; i -= 2) {
      if (!((a[i] == c[i] && a[i - 1] == c[i - 1]) || (a[i] == c[i - 1] && a[i - 1] == c[i]))) {
        f = 0;
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
