#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  string s;
  cin >> T;
  ll maxi_n = 2 * 1e5 + 100;
  while (T--) {
    cin >> n >> s;
    unordered_map<ll, ll> mp;
    ll x = 0, y = 0;
    mp[x * maxi_n + y]++;
    ll res = 0;
    for (auto& c : s) {
      if (c == 'U') {
        x++;
      } else if (c == 'D') {
        x--;
      } else if (c == 'L') {
        y--;
      } else {
        y++;
      }
      res += mp[x * maxi_n + y];
      mp[x * maxi_n + y]++;
    }
    cout << res << endl;
  }
}