#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    string s;
    cin >> n >> s;
    if (count(s.begin(), s.end(), 'R') == 0 || count(s.begin(), s.end(), 'D') == 0) {
      cout << n << "\n";
      continue;
    }
    ll x = 0, y = 0;
    for (auto& c : s) {
      if (c == 'R') {
        y++;
      } else {
        x++;
      }
    }
    ll ex_x = n - 1 - x;
    ll ex_y = n - 1 - y;
    ll can_x = 0, can_y = 0;
    x = 0, y = 0;
    ll get_x = 0, get_y = 0;
    ll res = 1 + ex_x * ex_y;
    for (auto& c : s) {
      if (c == 'R') {
        can_y |= 1;
        get_x = 0;
        y++;
      } else {
        can_x |= 1;
        get_y = 0;
        x++;
      }
      if (can_x) {
        if (!get_x) {
          res += ex_x;
          get_x = 1;
        }
      }
      if (can_y) {
        if (!get_y) {
          res += ex_y;
          get_y = 1;
        }
      }
      res++;
    }
    cout << res << "\n";
  }
}
