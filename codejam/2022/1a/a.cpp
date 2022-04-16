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
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    string s;
    cin >> s;
    ll n = s.size();
    string res;
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && s[i] == s[j];) j++;
      ll cur = s[i] - 'a';
      if (j < n && s[j] - 'a' > cur) {
        res += string(j - i, s[i]);
      }
      res += string(j - i, s[i]);
    }
    cout << res << "\n";
  }
}
