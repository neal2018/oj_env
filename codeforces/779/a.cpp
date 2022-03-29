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
    cin >> n;
    string s;
    cin >> s;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      if (i < n - 1 && s.substr(i, 2) == "00") {
        res += 2;
      }
      if (i < n - 2 && s.substr(i, 3) == "010") {
        res += 1;
      }
    }
    cout << res << "\n";
  }
}
