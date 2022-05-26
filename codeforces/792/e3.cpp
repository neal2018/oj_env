#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    for (int i = 0, x; i < n; i++) cin >> x, mp[x]++;
    ll remain = k, mex = 0;
    vector<ll> surplus;
    for (auto [kk, vv] : mp) {
      while (remain && mex < kk) remain--, mex++;
      if (mex == kk) {
        mex++;
      } else {
        surplus.push_back(vv);
      }
    }
    ll res = surplus.size();
    sort(surplus.begin(), surplus.end());
    for (auto& x : surplus) {
      if (k >= x) k -= x, res--;
    }
    cout << res << "\n";
  }
}
