#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k, w, q;
  string s;
  cin >> n >> s >> k >> w >> q;
  vector<ll> a;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') a.push_back(i);
  }
  ll res = 0;
  for (auto& x : a) {
    ll cur = 0;
    for (auto& t : {x - k, x + k}) {
      auto it = lower_bound(a.begin(), a.end(), t);
      ll diff = 1e10;
      if (it != a.end()) diff = min(diff, abs(*it - t));
      if (it != a.begin()) diff = min(diff, abs(*(--it) - t));
      cur += max(0ll, w - diff * q);
    }
    res = max(res, cur);
  }
  cout << res << "\n";
}
