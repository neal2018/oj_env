#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  ll res = 1e18;
  for (int i = 0; i < 10; i++) {
    map<ll, ll> mp;
    for (auto& s : a) {
      for (int j = 0; j < 10; j++) {
        if (s[j] == '0' + i) mp[j]++;
      }
    }
    ll cur = 0;
    for (auto [k, v] : mp) {
      cur = max(cur, k + (v - 1) * 10);
    }
    res = min(res, cur);
  }
  cout << res << "\n";
}
