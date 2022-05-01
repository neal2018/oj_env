#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto func = [&]() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) {
      if ((a[i] % 2) != (a[i % 2] % 2)) return false;
    }
    return true;
  };
  int T;
  cin >> T;
  while (T--) {
    cout << (func() ? "YES\n" : "NO\n");
  }
}
