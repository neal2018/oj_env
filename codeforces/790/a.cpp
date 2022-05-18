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
    cout << (s[0] + s[1] + s[2] == s[3] + s[4] + s[5] ? "YES\n" : "NO\n");
  }
}
