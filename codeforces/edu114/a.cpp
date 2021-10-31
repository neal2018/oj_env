#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        cout << '(';
      }
      for (int j = 0; j <= i; j++) {
        cout << ')';
      }
      for (int j = i + 1; j < n; j++) {
        cout << "()";
      }
      cout << '\n';
    }
  }
}