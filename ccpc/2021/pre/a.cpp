#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << (n - n / 2) + ((n + 1) / 2 - (n + 2) / 6) << endl;
  }
  // ll maxi = 1e3;
  // vector<pair<ll, ll>> save;
  // for (int x = 1; x <= maxi; x++) {
  //   if (x & 1) {
  //     save.push_back({x, 3 * x + 1});
  //   } else {
  //     save.push_back({x / 2, x});
  //   }
  // }
  // for (int i = 1; i < 100; i++) {
  //   ll cnt = 0;
  //   for (auto& [l, r] : save) {
  //     if (l <= i && r > i) cnt++;
  //   }
  //   cout << i << " " << cnt << endl;
  // }
}