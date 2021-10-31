#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
ll T, n;
string s;
void solve() {
  cin >> n >> s;
  ll i1 = -1, i2 = -2;
  for (ll l = 0, r = n - 1; l < r; l++, r--) {
    if (s[l] != s[r]) {
      i1 = l, i2 = r;
      break;
    }
  }
  if (i1 == -1) {
    cout << "0\n";
    return;
  }
  ll res = 1e9;
  for (char c : {s[i1], s[i2]}) {
    ll cnt = 0, f = 1;
    for (int l = 0, r = n - 1; l < r;) {
      if (s[l] != s[r]) {
        if (s[l] == c) {
          l++;
          cnt++;
        } else if (s[r] == c) {
          r--;
          cnt++;
        } else {
          f = 0;
          break;
        }
      } else {
        l++, r--;
      }
    }
    if (f) res = min(res, cnt);
  }
  cout << ((res == 1e9) ? -1 : res) << '\n';
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> T;
  while (T--) {
    solve();
  }
}