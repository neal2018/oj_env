#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int res = 1;
    for (int i = 0; i < s.size(); i++) {
      if (i == 0) {
        if (s[i] == '0') res = 0;
        if (s[i] == '?') res *= 9;
      } else {
        if (s[i] == '?') res *= 10;
      }
    }
    cout << res << "\n";
  }
}
