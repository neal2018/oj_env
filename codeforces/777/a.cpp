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
    string res;
    for (int i = 0; i < n / 3; i++) {
      res += "21";
    }
    if (n % 3 == 1) {
      res = "1" + res;
    } else if (n % 3 == 2) {
      res += "2";
    }
    cout << res << "\n";
  }
}
