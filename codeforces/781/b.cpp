#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (auto& x : a) cin >> x, mp[x]++;
    ll maxi = 0;
    for (auto& [k, v] : mp) {
      maxi = max(maxi, v);
    }
    ll res = 0;
    while (maxi < n) {
      res++;
      res += min(maxi, n - maxi);
      maxi += min(maxi, n - maxi);
    }
    cout << res << "\n";
  }
}
