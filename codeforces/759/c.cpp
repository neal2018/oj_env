#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    multiset<ll> pos, neg;
    ll maxi=0;
    for (ll i = 0, x; i < n; i++) {
      cin >> x;
      if (x > 0) pos.insert(x);
      if (x < 0) neg.insert(-x);
      maxi=max(maxi, abs(x));
    }
    ll total = 0;
    while (pos.size()) {
      total += (*pos.rbegin()) * 2;
      for (int _ = 0; _ < k && pos.size(); _++) {
        pos.erase(--pos.end());
      }
    }
    while (neg.size()) {
      total += (*neg.rbegin()) * 2;
      for (int _ = 0; _ < k && neg.size(); _++) {
        neg.erase(--neg.end());
      }
    }
    cout << total-maxi << '\n';
  }
}