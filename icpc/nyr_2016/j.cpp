#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int i;
    cin >> i;
    string s;
    cin >> s;
    ll res = 0, len = s.size();
    auto to_hex = [](ll x) {
      string res;
      while (x) {
        ll remain = x % 16;
        x /= 16;
        if (remain >= 10) {
          res += 'a' + remain - 10;
        } else {
          res += '0' + remain;
        }
      }
      reverse(res.begin(), res.end());
      return res;
    };
    auto to_oct = [](ll x) {
      string res;
      while (x) {
        ll remain = x % 8;
        x /= 8;
        res += '0' + remain;
      }
      reverse(res.begin(), res.end());
      if (res == "") res = "0";
      return res;
    };
    auto to_dec = [](string s, int k) -> ll {
      int maxi = *max_element(s.begin(), s.end()) - '0';
      if (maxi >= k) {
        return 0;
      }
      ll res = 0, len = s.size();
      for (int i = 0; i < len; i++) {
        res = res * k;
        if (isdigit(s[i])) {
          res += s[i] - '0';
        } else {
          res += s[i] - 'a' + 10;
        }
      }
      return res;
    };
    cout << i << " " << (to_dec(s, 8)) << " " << to_dec(s, 10) << " " << (to_dec(s, 16)) << "\n";
  }
}
