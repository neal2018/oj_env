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
    int cur = s[0] == '1';
    for (int i = 1; i < n; i++) {
      if (s[i] == '0') {
        cout << "+";
      } else {
        if (cur == 1) {
          cout << "-";
          cur--;
        } else {
          cout << "+";
          cur++;
        }
      }
    }
    cout << "\n";
  }
}
