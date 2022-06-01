#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int res = 0, first = -1, last = -1, one = 0;
    for (int i = 0; i < n; i++) {
      if (i < n - 1) {
        res += (s[i] - '0') * 10 + (s[i + 1] - '0');
      }
      if (s[i] == '1') {
        if (first == -1) first = i;
        last = i;
        one++;
      }
    }
    if (last != n - 1 && k >= (n - 1 - last) && one)
      res -= 10 - (last == 0), k -= (n - 1 - last), one--;
    if (first != 0 && k >= first && one && first != n - 1) res--, k -= first, one--;
    cout << res << "\n";
  }
}