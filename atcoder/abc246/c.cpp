#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k, t;
  cin >> n >> k >> t;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll res = 0;
  for (auto& x : a) {
    ll can = min(k, x / t);
    k -= can;
    x -= t * can;
  }
  sort(a.begin(), a.end(), greater<>());
  for (auto& x : a) {
    if (x < t && k > 0) {
      x = 0, k--;
    }
    res += x;
  }
  cout << res << "\n";
}
