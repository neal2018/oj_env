#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, d, c, m, res;
  string s;
  cin >> T;
  auto solve = [&] {

  };
  for (ll ttt = 1; ttt <= T; ttt++) {
    cin >> n >> d >> c >> m >> s;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
      if (s[i] == 'C') {
        if (c > 0) {
          c--;
        } else {
          break;
        }
      } else {
        if (d > 0) {
          d--, c += m;
          cnt++;
        } else {
          break;
        }
      }
    }
    ll dcnt = 0;
    for (auto& cc : s)
      if (cc == 'D') dcnt++;
    cout << "Case #" << ttt << ": " << (dcnt == cnt ? "YES" : "NO") << '\n';
  }
  return 0;
}