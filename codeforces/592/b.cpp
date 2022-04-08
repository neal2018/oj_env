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
    int n;
    string s;
    cin >> n >> s;
    int res = n;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        res = max({res, (i + 1) * 2, (n - i) * 2});
      }
    }
    cout << res << '\n';
  }
}
