#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
ll T, n;
void solve() {
  ll maxi = 1e9 + 10, mul = 1;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  for (ll i = 0; i < n && mul < maxi; i++) {
    mul = mul * (i + 2) / __gcd(mul, i + 2);
    if (a[i] % mul == 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> T;
  while (T--) solve();
}