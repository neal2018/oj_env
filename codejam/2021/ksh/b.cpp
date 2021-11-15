#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  string s;
  cin >> T;
  // auto solve = [&] {
  // };
  for (ll ttt = 1; ttt <= T; ttt++) {
    cin >> n;
    cin >> s;
    ll res = 0;
    map<char, string> mp;
    mp['R'] = "ROPA";
    mp['Y'] = "YOGA";
    mp['B'] = "BPGA";
    for (auto c : "RYB") {
      int rolling = 0;
      for (int i = 0; i < n; i++) {
        if (mp[c].find(s[i]) == string::npos) {
          if (rolling > 0) {
            rolling = 0;
            res++;
          }
        } else {
          rolling++;
        }
      }
      if (rolling > 0) {
        rolling = 0;
        res++;
      }
      // cout << res << '\n';
    }
    cout << "Case #" << ttt << ": " << res << '\n';
  }
  return 0;
}