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
    vector<ll> a(n);
    map<ll, ll> freq;
    for (auto &x : a) cin >> x, freq[x]++;
    auto check = [&](ll mid) {
      ll empty = 0;
      for (int i = 0; i < mid; i++) empty += freq.count(i) == 0;
      return empty <= k;
    };
    ll l = 0, r = n;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    vector<ll> sz;
    for (auto &[kk, vv] : freq) {
      if (kk > l) sz.push_back(vv);
    }
    sort(sz.begin(), sz.end());
    ll res = sz.size();
    for (auto x : sz) {
      ll minus = min(k, x);
      k -= minus, res -= (minus == x);
    }
    cout << res << "\n";
  }
}
