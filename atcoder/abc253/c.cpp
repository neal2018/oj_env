#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int q;
  cin >> q;
  map<int, int> mp;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      mp[x]++;
    } else if (t == 2) {
      int x, c;
      cin >> x >> c;
      int minus = min(c, mp[x]);
      mp[x] -= minus;
      if (mp[x] == 0) mp.extract(x);
    } else {
      cout << (mp.rbegin()->first - mp.begin()->first) << "\n";
    }
  }
}