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
    auto b = a;
    sort(b.begin(), b.end());
    ll res = (1 << 30) - 1;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) res &= a[i];
    }
    cout << res << "\n";
  }
}
