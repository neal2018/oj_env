#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, n;
  cin >> T;
  string s;
  while (T--) {
    cin >> n >> s;
    string res = s;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'U') {
        res[i] = 'D';
      } else if (s[i] == 'D') {
        res[i] = 'U';
      }
    }
    cout << res << endl;
  }
}