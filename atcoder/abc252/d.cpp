#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  map<ll, ll> mp;
  for (int i = 0, x; i < n; i++) cin >> x, mp[x]++;
  ll res = n * (n - 1) * (n - 2) / 6;
  for (auto [k, v] : mp) {
    res -= v * (v - 1) * (v - 2) / 6;
    res -= v * (v - 1) / 2 * (n - v);
  }
  cout << res << "\n";
}
