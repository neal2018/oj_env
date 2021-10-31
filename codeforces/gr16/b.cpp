#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T;
  string s;
  cin >> T;
  while (T--) {
    cin >> s;
    int cnt = 0;
    int streaking = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        streaking = 1;
      } else {
        if (streaking == 1) {
          cnt++;
        }
        streaking = 0;
      }
    }
    if (streaking == 1) {
      cnt++;
    }
    cout << min(2, cnt) << '\n';
  }
}