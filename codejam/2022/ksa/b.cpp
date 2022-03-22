#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    string s;
    cin >> s;
    ll total = 0;
    for (auto& c : s) total += (c - '0');
    ll add = total % 9;
    add = (add == 0 ? 0 : 9 - add);
    ll n = s.size();
    ll f = 1;
    cout << "Case #" << case_no << ": ";
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && s[i] == s[j];) j++;
      ll cur = s[i] - '0';
      if (f) {
        if (add < cur) {
          if (i != 0 || add != 0) {
            cout << add << string(j - i, s[i]);
            f = 0;
            continue;
          } else {
            if (j - i > 1) {
              cout << s[i] << add << string(j - i - 1, s[i]);
              f = 0;
              continue;
            }
          }
        } else if (add == cur) {
          if (!(j < n && s[j] - '0' < add)) {
            cout << add << string(j - i, s[i]);
            f = 0;
            continue;
          }
        }
      }
      cout << string(j - i, s[i]);
    }
    if (f) cout << add;
    cout << "\n";
  }
}
