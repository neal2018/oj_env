#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    int q, d;
    cin >> q >> d;
    map<int, int> mp;
    for (int i = 0; i <= 100; i += 10) {
      int x = i + d;
      if (!mp.count(x % d)) mp[x % d] = 1e9;
      mp[x % d] = min(mp[x % d], x);
    }
    for (int i = d * 10; i <= d * 10 + 10; i += 1) {
      int x = i;
      if (!mp.count(x % d)) mp[x % d] = 1e9;
      mp[x % d] = min(mp[x % d], x);
    }
    while (q--) {
      int x;
      cin >> x;
      if (x >= mp[x % d]) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}