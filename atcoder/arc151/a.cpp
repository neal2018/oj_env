#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int diff = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) diff++;
  }
  if (diff & 1) {
    cout << "-1\n";
    return 0;
  }
  int b1 = diff / 2;
  int b2 = diff / 2;
  string u;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      u += '0';
    } else {
      if (s[i] == '0') {
        if (b1 > 0) {
          u += '0', b1--;
        } else {
          u += '1';
        }
      } else {
        if (b2 > 0) {
          u += '0', b2--;
        } else {
          u += '1';
        }
      }
    }
  }
  cout << u << "\n";
}
