#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] != s[n - 1]) {
      if (n % 2) {
        cout << "Chikapu" << '\n';
      } else {
        cout << "Bash" << '\n';
      }
    } else {
      if (n % 2 == 0) {
        cout << "Chikapu" << '\n';
      } else {
        cout << "Bash" << '\n';
      }
    }
  }
}
