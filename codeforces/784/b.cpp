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
    map<ll, ll> mp;
    for (auto& x : a) cin >> x, mp[x]++;
    ll res = -1;
    for (auto& [k, v] : mp) {
      if (v >= 3) res = k;
    }
    cout << res << "\n";
  }
}
