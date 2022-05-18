#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    ll n = s.size();
    ll one = count(s.begin(), s.end(), '1');
    ll zero = 0, res = 1e18;
    if (one == 0) res = 0;
    for (int i = 0, j = 0; i < n; i++) {
      if (s[i] == '0') zero++;
      while (i - j + 1 > one && j < i) {
        if (s[j] == '0') zero--;
        j++;
      }
      if (i - j + 1 == one) {
        res = min(res, zero);
      }
    }
    cout << res << "\n";
  }
}
