#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    multiset<ll> need, remain;
    for (ll i = 1; i <= n; i++) need.insert(i);
    for (auto x : a) {
      if (need.count(x)) {
        need.erase(x);
      } else {
        remain.insert(x);
      }
    }
    ll cnt = remain.size();
    while (remain.size() && (*remain.begin() - 1) / 2 >= *need.begin()) {
      remain.erase(remain.begin());
      need.erase(need.begin());
    }
    if (need.size()) {
      cout << -1 << '\n';
    } else {
      cout << cnt << '\n';
    }
  }
}