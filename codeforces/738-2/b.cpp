#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  cin >> T;
  string s;
  while (T--) {
    cin >> n;
    cin >> s;
    string res = s;
    char prev = 'R';
    for (ll i = 0; i < n; i++) {
      if (s[i] != '?') {
        prev = s[i];
        if (i % 2 == 0) {
          prev = (prev == 'B' ? 'R' : 'B');
        }
        break;
      }
    }
    for (ll i = 0; i < n; i++) {
      if (s[i] == '?') {
        res[i] = (prev == 'B' ? 'R' : 'B');
      }
      prev = res[i];
    }
    cout << res << endl;
  }
  return 0;
}
