#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    map<ll, ll> mp;
    ll maxi = 1e18;
    for (int i = 0; i < n; i++) {
      if (a[i] < maxi) {
        maxi = a[i];
        mp[i] = a[i];
      }
    }
    while (m--) {
      ll k, d;
      cin >> k >> d, k--;
      a[k] -= d;
      auto it = --mp.upper_bound(k);
      if (it->second > a[k]) {
        if (it->first < k) it++;
        while (it != mp.end() && it->second >= a[k]) it = mp.erase(it);
        mp[k] = a[k];
      }
      cout << mp.size() << ' ';
    }
    cout << "\n";
  }
}
