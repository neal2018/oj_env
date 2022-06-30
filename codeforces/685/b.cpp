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
    int n, q;
    string s;
    cin >> n >> q >> s;
    while (q--) {
      int l, r;
      cin >> l >> r, l--;
      if (r - l < 2) {
        cout << "NO\n";
      } else {
        if (count(s.begin(), s.begin() + l, s[l]) || count(s.begin() + r, s.end(), s[r - 1])) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    }
  }
}
