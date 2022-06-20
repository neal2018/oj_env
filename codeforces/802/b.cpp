#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    if (s[0] != '9') {
      string t(n, '?');
      for (auto i : views::iota(0, n)) {
        t[i] = 9 - (s[i] - '0') + '0';
      }
      cout << t << '\n';
    } else {
      string t(n, '?');
      int carry = 0;
      for (int i = n - 1; i >= 0; i--) {
        int cur = s[i] - '0' + carry;
        int need = cur <= 1 ? 1 : 11;
        t[i] = char(need - cur + '0');
        carry = need / 10;
      }
      cout << t << '\n';
    }
  }
}
